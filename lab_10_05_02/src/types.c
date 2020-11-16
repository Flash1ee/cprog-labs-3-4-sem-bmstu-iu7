#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "utils.h"

node_t *create_node(char *str)
{
    if (!str)
    {
        return NULL;
    }
    node_t *node = malloc(sizeof(node_t));
    if (!node)
    {
        return NULL;
    }
    strncpy(node->data, str, BUF_SIZE);
    node->next = NULL;
    return node;
}
node_t *list_add_back(node_t *new_node, node_t **head)
{
    if (!new_node || !head)
    {
        return NULL;
    }
    if (!(*head))
    {
        *head = new_node;
        return *head;
    }
    node_t *cur;
    node_t *prev;
    for (cur = *head; cur; cur = cur->next)
    {
        prev = cur;
    }
    prev->next = new_node;
    return *head;
}
void free_list(node_t *head)
{
    if (!head)
    {
        return;
    }
    node_t *next = NULL;
    for (; head; head = next)
    {
        next = head->next;
        free_node(head);
    }
}
void free_node(node_t *node)
{
    // free(node->data);
    free(node);
}
void print_list(node_t *head)
{
    node_t *cur = NULL;
    char buf[BUF_SIZE + 1] = {0};
    for (cur = head; cur; cur = cur->next)
    {
        size_t i;
        for (i = 0; i < BUF_SIZE && cur->data[i] != '\0'; i++)
        {
            buf[i] = cur->data[i];
        }

        buf[i] = '\0';
        printf("%s\n", buf);
        memset(buf, 0, BUF_SIZE + 1);
    }
}