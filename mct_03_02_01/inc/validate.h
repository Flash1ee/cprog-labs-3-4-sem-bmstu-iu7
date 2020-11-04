#ifndef _VALIDATE_H_
#define _VALIDATE_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NOT_UNSIGNED -1
#define VALIDATE_ERR -3
#define PARSE_ERR -5


int valid_u_num(char *str, size_t *num);


#endif //_VALIDATE_H_