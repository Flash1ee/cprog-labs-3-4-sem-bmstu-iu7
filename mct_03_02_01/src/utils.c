#include "utils.h"

int isprime(size_t num) {
    if (num < 2) {
        return NOT_PRIME;
    }
    for (size_t i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return NOT_PRIME;
        }
    }
    return PRIME;
}

