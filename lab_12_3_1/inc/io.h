/**
*@file io.h
*@author Dmitry Varin (you@domain.com)
*@brief Заголовочный файл описывающий функии ввода/вывода.
*@version 0.1
*@date 2020-09-25
*
*
 */
#ifndef IO_H_
#define IO_H_

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



#endif // _IO_H