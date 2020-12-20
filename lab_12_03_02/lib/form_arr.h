#ifndef __FORM_ARR_H__
#define __FORM_ARR_H__

int fill_prime(int *arr, int n);

// user allocate requirenment size
int form_arr_user_size(int *src, int src_n, int *dst, int dst_n);

// signal for allocate dst arr
int form_arr_my_size(int *src, int src_n, int *dst, int *dst_n);

void print();
#endif  //  __FORM_ARR_H__