/**
*@file io.h
*@author Dmitry Varin (you@domain.com)
*@brief Заголовочный файл описывающий функии ввода/вывода.
*@version 0.1
*@date 2020-09-25
*
*
 */
#ifndef _IO_H
#define _IO_H

#include <stdio.h>
#include <stdlib.h>

/**
*@brief Функция считает количество элементов в файле размером size.
*
*@param f Файловая переменная, указывающая на обрабатываемый файл.
*@param size Размер единицы данных.
*@return int код ошибки
*           EXIT_SUCCESS - успешное завершение;
*           EMPTY_FILE - файл пуст;
*           REAR_ERR - не удалось дойти до конца файла.
 */
int f_int_cnt(FILE *f, size_t *size);
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



#endif // _IO_H