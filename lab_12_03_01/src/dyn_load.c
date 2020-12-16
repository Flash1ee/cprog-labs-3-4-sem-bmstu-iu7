#ifdef DYN_LOAD
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "retcodes.h"
#include "io.h"
#include "sort.h"
#include "key.h"
#include "arr.h"
#include "dyn_load.h"

#define ALLOCATION_ERR 5

int dyn_load(int argc, char *argv[])
{
    if (argc != 3 && argc != 4)
        return ARG_ERR;
    if (argc == 4 && strcmp(argv[3], "f") != 0)
        return ARG_ERR;

    int filter = 0;
    if (argc == 4)
        filter = 1;

    FILE *in, *out;
    int rc = 0;
    size_t n = 0;

    in = fopen(argv[1], "r");
    if (!in) {
        return READ_ERR;
    }
    rc = f_int_cnt(in, &n);
    if (rc)
    {
        fclose(in);
        return rc;
    }

    int *arr = NULL;
    rc = create((void *)&arr, n, sizeof(int));
    arr = (int *)arr;
    if (rc)
    {
        fclose(in);
        return ALLOCATION_ERR;
    }

    int *beg = arr;
    int *end = arr + n;
    fseek(in, 0, SEEK_SET);


    void *hlib;
    hlib = dlopen("libarr.so", RTLD_NOW);
    if (!hlib) {
        fclose(in);
        destroy(arr, n, sizeof(int));
        return OPEN_LIB_ERR;
    }
    fn_key_t key = (fn_key_t)dlsym(hlib, "key");
    fn_fill_t fill = (fn_fill_t)dlsym(hlib, "fill");
    fn_print_t print = (fn_print_t)dlsym(hlib, "print");

    if (!key || !fill || !print) {
        dlclose(hlib);
        fclose(in);
        destroy(arr, n, sizeof(int));
        return LOAD_FUNC_ERR;
    }

    rc = fill(in, beg, end);
    if (rc)
    {
        destroy(arr, n, sizeof(int));
        dlclose(hlib);
        fclose(in);
        return READ_ERR;
    }

    out = fopen(argv[2], "w");
    if (!out) {
        fclose(in);
        destroy(arr, n, sizeof(int));
        dlclose(in);
        return READ_ERR;
    }

    if (filter)
    {
        int *dst_bg = NULL;
        int *dst_end = NULL;
        rc = key(arr, end, &dst_bg, &dst_end);
        if (rc)
        {
            destroy(arr, n, sizeof(int));
            fclose(in);
            fclose(out);
            dlclose(hlib);
            return rc;
        }

        n = dst_end - dst_bg;
        mysort(dst_bg, n, sizeof(int), cmp_i);
        print(out, dst_bg, n);
        destroy(dst_bg, n, sizeof(int));
    }
    else
    {
        mysort(arr, n, sizeof(int), cmp_i);
        print(out, beg, n);
    }
    destroy(arr, n, sizeof(int));
    fclose(in);
    fclose(out);
    dlclose(hlib);

    return rc;
}

#endif