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
*@brief Универсальный поиск индекса последнего отрицательного элемента
*
*@param beg Указатель на начало массива
*@param end Указатель на конец массива
*@param size Размер одного элемента
*@return int Индекс или n - количество чисел в массиве.
 */
int last_neg(char *beg, char *end, size_t size);

#endif // KEY_H_