#include "list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

d_linked_list_t *create_d_linked_list() {
    d_linked_list_t *tmp = (d_linked_list_t *)malloc(sizeof(d_linked_list_t));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void delete_d_linked_list(d_linked_list_t *list) {
    node_t *tmp = list->head;
    node_t *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(list);
}

void print(d_linked_list_t *list) {
    assert(list);
    node_t *tmp = list->head;
    if (!tmp) {
        puts("EMPTY");
        return;
    }
    while (tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    puts("");
}

void push_back(d_linked_list_t *list, int value) {
    assert(list);
    node_t *tmp = calloc(1, sizeof(node_t));
    assert(tmp);

    tmp->data = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (!list->head) {
        list->head = tmp;
    }
    list->size++;
}

void push_front(d_linked_list_t *list, int data) {
    node_t *tmp = calloc(1, sizeof(node_t));
    assert(tmp);
    tmp->data = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

int pop_front(d_linked_list_t *list) {
    node_t *prev;
    int tmp;

    assert(list->head);

    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->data;
    free(prev);

    list->size--;
    return tmp;
}
int delete_node(d_linked_list_t *list, node_t *node) {
    assert(list && node);
    int tmp = 0;

    node_t *elm = node;

    if (node->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->data;

    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;

    return tmp;
}