#ifndef __FILTER_LIB_H__
#define __FILTER_LIB_H__

#include <stdlib.h>

#define READ_ERR 2
#define ALLOCATION_ERR 4
#define PTR_ERR 5
#define FILTER_ERR 6

/**
*@brief Фильтрация массива
* Условие В массиве остаются элементы от 0-го до p-го, где p - индекс
* последнего отрицательного элемента, или n - количество элементов, в случае отсуствия отрицательных
*@param pb_src Указатель на массив чисел int, откуда копируются данные.
*@param pe_src Указатель на конец массив чисел int, откуда копируются данные.
*@param pb_dst Указатель на указатель на массив чисел int, куда копируются данные.
*@param pe_dst Указатель на указатель на конец массив чисел int, куда копируются данные.
*@return Код ошибки:
* PTR_ERR - pb_src || pe_src равны null\\\
* ALLOCATION_ERROR - ошибка выделения памяти\\\
* EXIT_SUCCESS - успешное выполнение.  
 */
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);



#endif  //  __FILTER__LIB_H__