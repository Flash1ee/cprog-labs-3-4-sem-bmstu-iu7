/**
*@file err.h
*@author Dmitry Varin (you@domain.com)
*@brief Заголовочный файл, описывающий код ошибок
*@version 0.1
*@date 2020-09-25
 */

#ifndef ERR_H_
#define ERR_H_

/**
*@brief Неверное количество аргументов
 */
#define ARG_ERR 1
/**
*@brief Ошибка чтения файла
 */
#define READ_ERR 2
/**
*@brief Файл пуст
 */
#define EMPTY_FILE 3
/**
*@brief Ошибка выделения памяти
 */
#define ALLOCATION_ERR 4
/**
*@brief Некорректные указатели(NULL)
 */
#define PTR_ERR 5

/*@brief 
 */
#define FILTER_ERR 6


#endif // ERR_H_