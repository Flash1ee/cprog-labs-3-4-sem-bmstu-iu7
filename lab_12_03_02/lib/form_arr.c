#include <stdio.h>
#include <stdlib.h>
#include "form_arr.h"
#include "prime.h"

int fill_prime(int *arr, int n) {
    if (!arr || !n) {
        return EXIT_FAILURE;
    }

    size_t cur_len = 0;

    for (size_t i = 2; cur_len < n; i++) {
        if (is_prime(i)) {
            arr[cur_len++] = i;
        }
    }
    return EXIT_SUCCESS;
}
// return len_dst
int form_arr_user_size(int *src, int src_n, int *dst, int dst_n) { //correct dst_n
    if (src_n < 2) {
        return 0;
    }
    size_t dst_size = 0;
    int i = 0;

    while (i < src_n - 1) {
        if (src[i] % 2 == 0) {
            dst[dst_size++] = src[i + 1];
        }
        i++;
    }
    return dst_size;
}

int form_arr_my_size(int *src, int src_n, int *dst, int *dst_n) {
    if (!dst_n) {
        return EXIT_FAILURE;
    }
    int cnt = 0;

    for (size_t i = 0; i < src_n - 1; i++) {
        if (src[i] % 2 == 0) {
            cnt++;
        }
    }
    if (cnt > *dst_n) {
        *dst_n = cnt;
        return -1;
    }
    cnt = 0;
    int i = 0;
    while (i < src_n - 1) {
        if (src[i] % 2 == 0) {
            dst[cnt++] = src[i + 1];
        }
        i++;
    }
    *dst_n = cnt;

    return EXIT_SUCCESS;
}
void print() {
    printf("MAMA");
}