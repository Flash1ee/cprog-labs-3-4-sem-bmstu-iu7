/**
*@file err.h
*@author Dmitry Varin (you@domain.com)
*@brief Заголовочный файл, описывающий код ошибок
*@version 0.1
*@date 2020-09-25
*
 */
#ifndef _ERR_H
#define _ERR_H

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


#endif // _ERR_H