#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

size_t get_size(char *filename)
{
    size_t count = 0;
    if (!filename)
    {
        return count;
    }
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        return count;
    }
    char *tmp = NULL;
    size_t n = 0, tmp_h, tmp_min;

    while (getline(&tmp, &n, f) != -1)
    {
        free(tmp);
        n = 0;
        if (fscanf(f, "%zu:%zu\n", &tmp_h, &tmp_min) != 2 || validate_time(tmp_h, tmp_min))
        {
            count = 0;
            fclose(f);
            return count;
        }
        count++;
    }
    free(tmp);
    fclose(f);

    return count;
}
int validate_time(size_t hour, size_t min)
{
    if (hour > MAX_HOUR || min > MAX_MIN)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
int fill_list(char *filename, data_t **data, size_t cnt)
{
    if (!filename || !data || !cnt)
    {
        return ARG_ERR;
    }

    FILE *f = fopen(filename, "r");
    if (!f)
    {
        return F_READ_ERR;
    }
    data_t *list = create_list(cnt);
    if (!list)
    {
        fclose(f);
        return ALLOC_ERR;
    }
    char *tmp = NULL;
    size_t n = 0, tmp_h, tmp_min;
    for (size_t i = 0; i < cnt; i++)
    {
        if (getline(&tmp, &n, f) == -1)
        {
            free(tmp);
            free_arr(list);
            fclose(f);
            return F_READ_ERR;
        }
        if (fscanf(f, "%zu%*[:]%zu\n", &tmp_h, &tmp_min) != 2 || validate_time(tmp_h, tmp_min))
        {
            free(tmp);
            free_arr(list);
            fclose(f);
            return F_READ_ERR;
        }
        tmp[strlen(tmp) - 1] = '\0';
        list->arr[i].describe = strdup(tmp);
        if (!list->arr[i].describe)
        {
            free(tmp);
            free_arr(list);
            fclose(f);
            return ALLOC_ERR;
        }
        list->arr[i].hours = tmp_h;
        list->arr[i].min = tmp_min;
        list->len++;
        free(tmp);
        tmp = NULL;
    }
    fclose(f);
    *data = list;
    return EXIT_SUCCESS;
}
int add_list(data_t **data, node_t **head)
{
    char *tmp = NULL;
    size_t n = 0, tmp_h, tmp_min;
    printf("Input task:\n");
    if (getline(&tmp, &n, stdin) == -1)
    {
        free(tmp);
        free_arr(*data);
        return F_READ_ERR;
    }
    printf("Input time of start in format [XX:YY]\n");
    if (scanf("%zu:%zu", &tmp_h, &tmp_min) != 2 || validate_time(tmp_h, tmp_min))
    {
        free(tmp);
        free_arr(*data);
        return F_READ_ERR;
    }
    clean_buf();
    if (!(*data))
    {
        *data = create_list(1);
        if (!(*data))
        {
            return ALLOC_ERR;
        }
    }
    if ((*data)->len == (*data)->capacity)
    {
        task_t *temp = realloc((*data)->arr, (*data)->len * K * sizeof(task_t));
        if (!temp)
        {
            free(tmp);
            free_arr(*data);
            return ALLOC_ERR;
        }
        (*data)->arr = temp;
        (*data)->capacity = (*data)->len * K;
        *head = update_list_nodes(head, *data);
        if (!(*head))
        {
            return CREATE_LIST_NODE_ER;
        }
    }
    tmp[strlen(tmp) - 1] = '\0';
    (*data)->arr[(*data)->len].describe = strdup(tmp);
    if (!(*data)->arr[(*data)->len].describe)
    {
        free(tmp);
        free_arr(*data);
        return ALLOC_ERR;
    }
    (*data)->arr[(*data)->len].hours = tmp_h;
    (*data)->arr[(*data)->len].min = tmp_min;
    (*data)->len++;
    printf("Success input\n");
    free(tmp);

    return EXIT_SUCCESS;
}
data_t *create_list(size_t cnt)
{
    data_t *list = malloc(sizeof(data_t));
    if (!list)
    {
        return NULL;
    }
    list->arr = calloc(cnt, sizeof(task_t));
    if (!list->arr)
    {
        free(list);
        return NULL;
    }

    list->capacity = cnt;
    list->len = 0;

    return list;
}
void free_arr(data_t *list)
{
    for (size_t i = 0; i < list->len; i++)
    {
        free(list->arr[i].describe);
    }
    free(list->arr);
    free(list);
}