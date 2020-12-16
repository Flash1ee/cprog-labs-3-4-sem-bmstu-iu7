#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>

// typedef struct node node_t;

struct node {
    int data;
    struct node *next; 
    struct node *prev;
};

typedef struct node node_t;

typedef struct {
    size_t size;
    node_t *head;
    node_t *tail;
} d_linked_list_t;

d_linked_list_t* create_d_linked_list();
void delete_d_linked_list(d_linked_list_t *list);

void print(d_linked_list_t *list);
void bubble_sort(d_linked_list_t *list);

void push_back(d_linked_list_t *list, int value);
void push_front(d_linked_list_t *list, int data);
int pop_front(d_linked_list_t *list);
void insert_bef_elem(d_linked_list_t *list, node_t *elm, int value);
void insert_sort(d_linked_list_t **list);

int delete_node(d_linked_list_t *list, node_t *node);

#endif // __LIST_H__