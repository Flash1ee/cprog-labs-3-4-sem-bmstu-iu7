#include <assert.h>
#include "prime.h"

int is_prime(int num) {
    assert(num >= 0);

    if (num < 2) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}