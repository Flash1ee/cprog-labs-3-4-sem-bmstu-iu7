#include <stdio.h>
#include "list.h"


int main() {

    int size = 0;
    if (scanf("%d", &size) != 1) {
        return EXIT_FAILURE;
    }
    int tmp = 0;
    d_linked_list_t *list = create_d_linked_list();
    if (!list) {
        return EXIT_FAILURE;
    }
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &tmp) != 1) {
            delete_d_linked_list(list);
            return EXIT_FAILURE;
        }
        push_back(list, tmp);
    }
    print(list);
    if (list->size) {
        insert_sort(&list, cmp);
        print(list);
    }
    else {
        puts("EMPTY");
    }
    delete_d_linked_list(list);
    return 0;
}