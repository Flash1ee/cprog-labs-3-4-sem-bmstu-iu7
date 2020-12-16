#ifndef __IO_LIB_H__
#define __IO_LIB_H__

#include <stdio.h>
#include <stdlib.h>

#define READ_ERR 2
/**
*@brief Считывания в массив чисел из файла
*
*@param f Файловая переменная, указывающая на обрабатываемый файл.
*@param pa Указатель на начало массива, в который идёт запись.
*@param pb Указатель на конец массива, в который идёт запись.
*@return int Возврат кода ошибки
*           EXIT_SUCCESS - успех.
*           READ_ERR - ошибка чтения.
 */
int fill(FILE *f, int *pa, int *pb);
/**
*@brief Запись массива в файл
*
*@param f Файловая переменная, указывающая файл.
*@param arr Указатель на массив.
*@param n Количество элементов в массиве.
 */
void print(FILE *f, int *arr, size_t n);


#endif  //  __IO_LIB_H__