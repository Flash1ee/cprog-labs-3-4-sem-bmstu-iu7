#include <assert.h>
#include "fib.h"

int is_fib(int num) {
    int a = 0;
    int b = 1;
    if (num == a || num == b) {
        return TRUE;
    }
    int c = a + b;
    while (c <= num) {
        if (c == num) {
            return TRUE;
        }
        a = b;
        b = c;
        c = a + b;
    }
    return FALSE;
}
void delete_fib(d_linked_list_t *list) {
    assert(list);
    node_t *next = NULL;
    for (node_t *cur = list->head; cur != NULL; cur = next) {
        next = cur->next;
        if (is_fib(cur->data) == TRUE) {
            delete_node(list, cur);
        }
    }
}