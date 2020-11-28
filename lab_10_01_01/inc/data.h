#ifndef _DATA_H_
#define _DATA_H_

#include <stdlib.h>

#include "utils.h"
#include "types.h"
#include "retcodes.h"

#define K 2
#define MAX_HOUR 23
#define MAX_MIN 59

size_t get_size(char *filename);
int validate_time(size_t hour, size_t min);
int add_list(data_t **data, node_t **head);
int fill_list(char *filename, data_t **data, size_t cnt);
data_t *create_list(size_t cnt);
void free_arr(data_t *list);

#endif // _DATA_H_