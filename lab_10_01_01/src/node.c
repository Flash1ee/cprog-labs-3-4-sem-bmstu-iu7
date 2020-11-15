#include <stdio.h>
#include "node.h"

node_t *create_node(task_t *data_add)
{
    if (!data_add || !data_add->describe)
    {
        return NULL;
    }
    node_t *node = calloc(1, sizeof(node_t));
    if (!node)
    {
        return NULL;
    }
    node->data = data_add;
    node->next = NULL;
    return node;
}

node_t *list_add_front(node_t *head, node_t *new_node)
{
    if (!new_node)
    {
        return NULL;
    }
    new_node->next = head;
    return new_node;
}

void free_node(node_t *node)
{
    free(node);
}
void print_list(node_t *head, FILE *out)
{
    node_t *cur = NULL;
    task_t *value = NULL;
    for (cur = head; cur; cur = cur->next)
    {
        value = (task_t *)(cur->data);
        fprintf(out, "%s\n%d:%d\n", value->describe, value->hours, value->min);
    }
}
void free_list(node_t *head)
{
    node_t *next;
    for (; head; head = next)
    {
        next = head->next;
        free_node(head);
    }
}

void insert(node_t **head, node_t *elem, node_t *before)
{
    if (!head || !elem || !before)
    {
        return;
    }
    // if (!(*head))
    // {
    //     if (before)
    //     {
    //         return;
    //     }
    //     *head = elem;
    //     return;
    // }
    node_t *cur, *prev = NULL;
    for (cur = *head; cur; cur = cur->next)
    {
        if (cur == before)
        {
            if (!prev)
            {
                elem->next = cur;
                *head = elem;
                return;
            }
            else
            {
                prev->next = elem;
                elem->next = cur;
                return;
            }
        }
        prev = cur;
    }
    if (!cur && cur == *head)
    {
        *head = elem;
    }
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head || !comparator)
    {
        return NULL;
    }

    node_t *new_head = NULL;
    node_t *cur;
    node_t *next = NULL;
    for (cur = head; cur; cur = next)
    {
        next = cur->next;
        sorted_insert(&new_head, cur, comparator);
    }
    return new_head;
}
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (!(*head))
    {
        *head = element;
        element->next = NULL;
        return;
    }
    node_t *cur = NULL;
    node_t *prev = NULL;
    node_t *new_head = NULL;

    for (cur = *head; cur && comparator(cur->data, element->data) < 0; cur = cur->next)
    {
        prev = cur;
    }
    if (!prev)
    {
        new_head = element;
        element->next = *head;
        *head = new_head;
    }
    else
    {
        prev->next = element;
        element->next = cur;
    }
}
int comparator(const void *a, const void *b)
{
    task_t *frst = (task_t *)a;
    task_t *sec = (task_t *)b;
    int res = frst->hours * 60 + frst->min - sec->hours * 60 - sec->min;

    return res;
}