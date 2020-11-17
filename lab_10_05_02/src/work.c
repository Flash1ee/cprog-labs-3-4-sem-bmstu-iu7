#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "work.h"
#include "retcodes.h"
#include "utils.h"

//Строка динамическая, после использования удалить..
int input_str(char **str)
{
    char *tmp = NULL;
    size_t n = 0;
    if (getline(&tmp, &n, stdin) == -1 || strlen(tmp) == 1)
    {
        free(tmp);
        return INPUT_ERR;
    }
    tmp[strlen(tmp) - 1] = '\0';
    *str = tmp;

    return EXIT_SUCCESS;
}
int convert_to_list(char *str, node_t **head)
{
    if (!str || !head)
    {
        free(str);
        free(*head);
        return ARG_ERR;
    }
    char buf[BUF_SIZE] = { 0 };
    char *ptr = str;
    int flag = 1;
    while (flag)
    {
        if (!strncpy(buf, ptr, BUF_SIZE))
        {
            free(str);
            free(*head);
            return COPY_ERR;
        }
        ptr += BUF_SIZE;
        if (strlen(buf) < BUF_SIZE || *ptr == '\0')
        {
            flag = 0;
        }
        node_t *new_node = create_node(buf);
        if (!new_node)
        {
            free(str);
            return ALLOC_ERR;
        }
        node_t *tmp = list_add_back(new_node, head);
        if (!tmp)
        {
            free(str);
            free_node(new_node);
            free_node(*head);
        }
        *head = tmp;
        memset(buf, 0, BUF_SIZE);
    }
    return EXIT_SUCCESS;
}
int output()
{
    char *res = NULL;
    int rc = input_str(&res);
    if (rc)
    {
        free(res);
        return rc;
    }
    node_t *head = NULL;
    rc = convert_to_list(res, &head);
    if (rc)
    {
        return rc;
    }
    print_list(head);
    free(res);
    free_list(head);
    return EXIT_SUCCESS;
}
node_t *append(node_t *a, node_t *b)
{
    if (!a || !b)
    {
        free_list(a);
        free_list(b);
        return NULL;
    }
    node_t *cur = NULL;
    node_t *prev = NULL;
    for (cur = a; cur; cur = cur->next)
    {
        prev = cur;
    }
    prev->next = b;
    return a;
}
int cat()
{
    char *str1 = NULL;
    char *str2 = NULL;
    int rc = input_str(&str1);
    if (rc)
    {
        return rc;
    }
    rc = input_str(&str2);
    if (rc)
    {
        free(str1);
        return rc;
    }
    node_t *head1 = NULL;
    node_t *head2 = NULL;
    rc = convert_to_list(str1, &head1);
    if (rc)
    {
        free(str2);
        return rc;
    }
    rc = convert_to_list(str2, &head2);
    if (rc)
    {
        free(str1);
        return rc;
    }
    node_t *head3 = append(head1, head2);
    if (!head3)
    {
        free(str1);
        free(str2);
        return rc;
    }

    print_list(head3);

    free(str1);
    free(str2);
    free_list(head3);
    return EXIT_SUCCESS;
}
int remove_spaces(char *str)
{
    if (!str)
    {
        return ARG_ERR;
    }
    char *cur;
    for (cur = str; *cur != '\0'; cur++)
    {
        if (*cur == ' ')
        {
            char *tmp = cur + 1;
            size_t cnt = 0;
            while (tmp && *tmp == ' ')
            {
                cnt++;
                tmp++;
            }
            if (!cnt)
            {
                continue;
            }
            for (tmp = cur + cnt + 1; *tmp != '\0'; tmp++)
            {
                size_t diff = tmp - cnt - cur;
                *(cur + diff) = *tmp;
            }
            *(tmp - cnt) = '\0';
        }
    }
    return EXIT_SUCCESS;
}
int one_sps_str()
{
    char *str1 = NULL;
    int rc = input_str(&str1);
    if (rc)
    {
        return rc;
    }
    rc = remove_spaces(str1);
    if (rc)
    {
        return rc;
    }
    node_t *head = NULL;
    rc = convert_to_list(str1, &head);
    if (rc)
    {
        return rc;
    }
    print_list(head);

    free(str1);
    free_list(head);
    return EXIT_SUCCESS;
}

size_t len_node_str(node_t *head, size_t *cnt_nodes)
{
    size_t len_str = 0;
    size_t nodes = 0;
    node_t *cur;
    for (cur = head; cur; cur = cur->next)
    {
        nodes++;
        for (size_t i = 0; i < BUF_SIZE; i++)
        {
            if (cur->data[i])
            {
                len_str++;
            }
        }
    }
    if (cnt_nodes)
    {
        *cnt_nodes = nodes;
    }
    return len_str;
}
char get_elem(node_t *head, size_t pos)
{
    size_t i = 0;
    for (node_t *cur = head; cur; cur = cur->next, i++)
    {
        for (size_t j = 0; j < BUF_SIZE && cur->data[j]; j++)
        {
            if ((i * BUF_SIZE + j) == pos)
            {
                return cur->data[j];
            }
        }
    }
    return 0;
}
int substr_in_str(node_t *head, char *substr)
{
    if (!head || !substr)
    {
        return ARG_ERR;
    }
    int res = -1;
    size_t len_str = len_node_str(head, NULL);
    size_t len_substr = strlen(substr);

    if (!len_str || !len_substr)
    {
        return ARG_ERR;
    }

    char elem;
    for (size_t i = 0; i <= len_str - len_substr; i++)
    {
        for (size_t j = 0; j < len_substr; j++)
        {
            elem = get_elem(head, i + j);
            if (substr[j] != elem)
            {
                break;
            }
            else if (j == len_substr - 1)
            {
                res = i;
                break;
            }
        }
        if (res != -1)
        {
            break;
        }
    }
    return res;
}
int search_substr()
{
    char *str1 = NULL;
    char *substr = NULL;
    int rc = input_str(&str1);
    if (rc)
    {
        return rc;
    }
    rc = input_str(&substr);
    if (rc)
    {
        free(str1);
        return rc;
    }
    node_t *head = NULL;
    rc = convert_to_list(str1, &head);
    if (rc)
    {
        return rc;
    }
    rc = substr_in_str(head, substr);
    if (rc == NOT_FOUND || rc >= 0)
    {
        printf("%d\n", rc);
        rc = EXIT_SUCCESS;
    }
    free(str1);
    free(substr);
    free_list(head);
    return rc;
}
