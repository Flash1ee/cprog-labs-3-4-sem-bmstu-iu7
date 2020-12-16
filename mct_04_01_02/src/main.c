#include "list.h"
#include "fib.h"

int main() {

    int arr[] = {1,3,144,5,8};
    d_linked_list_t *list = create_d_linked_list();

    for (size_t i = 0; i < 5; i++) {
        push_front(list, arr[i]);
    }
    print(list);
    // bubble_sort(list);
    delete_fib(list);
    print(list);
    delete_d_linked_list(list);
    return 0;
}