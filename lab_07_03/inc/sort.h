/**
*@file sort.h
*@author Dmitry Varin (you@domain.com)
*@brief Данный файл описывает функции, используемые при сортировке.
*@version 0.1
*@date 2020-09-25
*
 */
#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/**
*@brief Универсальная сортировка вставками
*
*@param first указатель на начало массива.
*@param len длина массива
*@param size размер одного элемента массива
*@param cmp функция сравнения элементов типа int
 */
void mysort(void *first, size_t len, size_t size, int (*cmp)(const void *, const void *));
/**
*@brief Функция сравнения двух чисел типа int
*
*@param a указатель на первый элемент.
*@param b указатель на второй элемент
*@return int 0, если элементы равны;
*           x > 0, если a > b;
*           x < 0, если a < b.
*@warning Ответсвтенность за корректность данных на вызывающей стороне.
 */
int cmp_i(const void *a, const void *b);

#endif // SORT_H_