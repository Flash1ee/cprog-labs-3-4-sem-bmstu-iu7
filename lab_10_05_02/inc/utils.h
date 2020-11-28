#ifndef _UTILS_H_
#define _UTILS_H_

#define BUF_SIZE 4


typedef enum
{
    OUT,
    CAT,
    RM_SPS,
    SEARCH_PSTR
} mode;

int input_process(mode *val);

#endif  // _UTILS_H_