#ifndef _UTILS_H_
#define _UTILS_H_

#define BUF_SIZE 4

// #define OUT "out"
// #define CAT "cat"
// #define RM_SPS "sps"
// #define SEARCH_PSTR "pos"

typedef enum
{
    OUT,
    CAT,
    RM_SPS,
    SEARCH_PSTR
} mode;

int input_process(mode *val);

#endif  // _UTILS_H_