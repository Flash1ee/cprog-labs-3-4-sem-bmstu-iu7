#ifndef _TYPES_H_
#define _TYPES_H_

#include <inttypes.h>

typedef struct
{
    char *describe;
    int8_t hours;
    int8_t min;
} task_t;

typedef struct
{
    task_t *arr;
    size_t len;
    size_t capacity;
} data_t;

typedef struct node_t node_t;
struct node_t
{
    void *data;
    node_t *next;
};

#endif // _TYPES_H_