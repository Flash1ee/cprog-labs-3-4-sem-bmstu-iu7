#include <stdlib.h>
#include "../inc/arr.h"

/**
*@brief Универсальная функция для выделения памяти под массив
*
*@param arr указатель на массив нужного типа
*@param n количество элементов
*@param size размер
*@return int код ошибки
 */
int create(void **arr, size_t n, size_t size)
{
    if (!arr || n < 1 || !size)
        return EXIT_FAILURE;
    *arr = malloc(n * size);
    if (!arr)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
/**
*@brief Универсальная функция освобождения памяти из под массива
*
*@param arr указатель на массив нужного типа
*@param n количество элементов
*@param size размер
*@return int код ошибки
 */
int destroy(void *arr, size_t n, size_t size)
{
    if (n < 1 || !size)
        return EXIT_FAILURE;
    
    for (char *cur = (char*) arr; cur < (char*)arr + size * n; cur+=size)
        *cur = 0;
    free(arr);
    return EXIT_SUCCESS;
}
