/**
*@file key.h
*@author Dmitry Varin (you@domain.com)
*@brief Файл описывающий функции фильтрации массива
*@version 0.1
*@date 2020-09-25
*
 */
#ifndef KEY_H_
#define KEY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
/**
*@brief Универсальный поиск индекса последнего отрицательного элемента
*
*@param beg Указатель на начало массива
*@param end Указатель на конец массива
*@param size Размер одного элемента
*@return int Индекс или n - количество чисел в массиве.
 */
int last_neg(char *beg, char *end, size_t size);

#endif // KEY_H_