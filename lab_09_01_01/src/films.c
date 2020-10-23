#include "films.h"

void add_sort(cinema *tmp, cinema list[], Field key, size_t *size)
{
    /*
    Процедура добавляет структуру tmp в упорядоченный массив cinema list
    */
    size_t j = 0;
    for (size_t i = 0; i < *size; i++)
        if ((key == TITLE && (strcmp(tmp->title, list[i].title) > 0)) || (key == NAME && (strcmp(tmp->name, list[i].name) > 0)) || (key == YEAR && ((tmp->year > list[i].year))))
            j = i + 1;
        else if ((key == TITLE && (!strcmp(tmp->title, list[i].title))) || (key == NAME && (!strcmp(tmp->name, list[i].name))) || (key == YEAR && ((tmp->year == list[i].year))))
        {
            j = i + 1;
            break;
        }
    if (j == 0)
    {
        for (size_t i = *size; i > 0; i--)
            list[i] = list[i - 1];
        *list = *tmp;
    }
    else if (j == *size)
        list[*size] = *tmp;
    else
    {
        for (size_t i = *size; i >= j; i--)
            list[i] = list[i - 1];
        list[j] = *tmp;
    }
    *size += 1;
}
int fill(FILE *f, cinema list[], size_t *size, Field key)
{
    /*
    Функция fill читает из файла строки и заполняет массив структурами
    В случае возникновения ошибки возвращает READ_STRUCT_ERROR
    */
    cinema tmp;
    if (fgets(tmp.title, N + 2, f))
    {
        if (tmp.title[strlen(tmp.title) - 1] != '\n' || strlen(tmp.title) < 2)
            return READ_STRUCT_ERR;
        fgets(tmp.name, N + 2, f);
        if (tmp.name[strlen(tmp.name) - 1] != '\n' || strlen(tmp.name) < 2)
            return READ_STRUCT_ERR;
        if (fscanf(f, "%ld\n", &tmp.year) != 1 || tmp.year <= 0)
            return READ_STRUCT_ERR;
        tmp.title[strlen(tmp.title) - 1] = '\0';
        tmp.name[strlen(tmp.name) - 1] = '\0';
        list[*size] = tmp;
        *size += 1;
        while (fgets(tmp.title, N + 2, f))
        {
            if (tmp.title[strlen(tmp.title) - 1] != '\n' || *size == MAX || strlen(tmp.title) < 2)
                return READ_STRUCT_ERR;
            fgets(tmp.name, N + 2, f);
            if (tmp.name[strlen(tmp.name) - 1] != '\n' || strlen(tmp.name) < 2)
                return READ_STRUCT_ERR;
            if (fscanf(f, "%ld\n", &tmp.year) != 1 || tmp.year <= 0)
                return READ_STRUCT_ERR;
            tmp.title[strlen(tmp.title) - 1] = '\0';
            tmp.name[strlen(tmp.name) - 1] = '\0';
            add_sort(&tmp, list, key, size);
        }
    }
    if (!feof(f))
        return READ_STRUCT_ERR;
    return EXIT_SUCCESS;
}

long bin_search(cinema list[], Field field, char key[], size_t size)
{
    /*
    Бинарный поиск по полю field ключа key
    Если key не найден, функция возвращает -1,
    позицию элемента в массиве cinema list[]
    */
    long l = 0;
    long r = size - 1;
    long mid;
    switch (field)
    {
    case TITLE:
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (!strcmp(list[mid].title, key))
                return mid;
            else if (strcmp(list[mid].title, key) > 0)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    case NAME:
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (!strcmp(list[mid].name, key))
                return mid;
            else if (strcmp(list[mid].name, key) > 0)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    case YEAR:
    {
        long date = strtol(key, NULL, 10);
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (list[mid].year == date)
                return mid;
            else if (list[mid].year > date)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    }
    return EXIT_SUCCESS;
}

void print(cinema list[], size_t len)
{
    for (size_t i = 0; i < len; i++)
        printf("%s\n%s\n%ld\n", list[i].title, list[i].name, list[i].year);
}