#include "list.h"


int main() {

    int arr[] = {1,3,-10,5,7,8};
    d_linked_list_t *list = create_d_linked_list();

    for (size_t i = 0; i < 6; i++) {
        push_front(list, arr[i]);
    }
    print(list);
    // bubble_sort(list);
    insert_sort(&list);
    print(list);
    delete_d_linked_list(list);
    return 0;
}