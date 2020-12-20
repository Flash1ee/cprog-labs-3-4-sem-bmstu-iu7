#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"


d_linked_list_t* create_d_linked_list() {
    d_linked_list_t *tmp = (d_linked_list_t*) malloc(sizeof(d_linked_list_t));
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
    while (tmp) {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
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


void insert_bef_elem(d_linked_list_t *list, node_t *elm, int value) {
    
    assert(elm);
    
    if (!elm->prev) {
        push_front(list, value);
        return;
    }
    node_t *ins = NULL;
    ins = malloc(sizeof(node_t));
    assert(ins);

    ins->data = value;
    ins->prev = elm->prev;

    elm->prev->next = ins;
    ins->next = elm;
    elm->prev = ins;
 
    list->size++;
}

int cmp(int a, int b) {
    if (a == b) {
        return 0;
    }
    if (a % 2 && b % 2 == 0) {
        return 1;
    }
    if (a % 2 == 0 && b % 2 == 1) {
        return -1;
    }

    if (a % 2 == 1 && b % 2 == 1) {
        if (a > b) {
            return 1;
        }
        return -1;
    }
    if (a % 2 == 0 && b % 2 == 0) {
        if (a > b) {
            return 1;
        }
        return -1;
    }
}
void insert_sort(d_linked_list_t **list, int (*cmp)(int, int)) {
    d_linked_list_t *new = create_d_linked_list();
    node_t *sort = NULL;
    node_t *unsort = NULL;
     
    push_front(new, pop_front(*list));

    unsort = (*list)->head;
    while (unsort) {
        sort = new->head;      
        while (sort && cmp(unsort->data, sort->data) == 1) {
            sort = sort->next;
        }
        if (sort) {
            insert_bef_elem(new, sort, unsort->data);
        } else {
            push_back(new, unsort->data);
        }
        unsort = unsort->next;
    }
    free(*list);
    *list = new;
}
void bubble_sort(d_linked_list_t *list) 
{ 
    node_t *tmp_next = NULL;
    node_t *tmp_prev = NULL;

    for (node_t *node1 = list->head; node1->next != NULL; node1 = node1->next) {
        for (node_t *node2 = node1->next; node2->next != NULL; node2 = node2->next) {
            if (node2->data > node2->next->data) {
                tmp_next = node2->next;
                tmp_prev = node2->prev;

                if (tmp_prev) {
                    tmp_prev->next = tmp_next;
                }
                if (tmp_next->next) {
                    tmp_next->next->prev = node2;
                }

                node2->next = tmp_next->next;
                node2->prev = tmp_next->prev;
                tmp_next->next = node2;
                tmp_next->prev = tmp_prev;

            }
        }
    }  
}

