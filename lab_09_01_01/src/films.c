#include "films.h"

long bin_search(cinema **list, Field field, char key[], size_t size)
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
            if (!strcmp(list[mid]->title, key))
                return mid;
            else if (strcmp(list[mid]->title, key) > 0)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    case NAME:
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (!strcmp(list[mid]->name, key))
                return mid;
            else if (strcmp(list[mid]->name, key) > 0)
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
            if (list[mid]->year == date)
                return mid;
            else if (list[mid]->year > date)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    }
    return EXIT_SUCCESS;
}

// void print(cinema list[], size_t len)
// {
//     for (size_t i = 0; i < len; i++)
//         printf("%s\n%s\n%ld\n", list[i].title, list[i].name, list[i].year);
// }
cinema **create_cinema_list(size_t n)
{
    cinema **list = malloc(sizeof(cinema *) * n);
    if (!list)
    {
        return NULL;
    }
    for (size_t i = 0; i < n; i++)
    {
        list[i] = calloc(1, sizeof(cinema));
        if (!list[i])
        {
            free_list(list, n);
            return NULL;
        }
    }
    return list;
}
void free_list(cinema **list, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(list[i]->title);
        free(list[i]->name);
        free(list[i]);
    }
    free(list);
}
int size_file(FILE *in, size_t *count)
{
    if (!in || !count)
    {
        return ARG_ERR;
    }
    size_t file_len = 0;
    size_t len = 0;

    char *title = NULL;
    char *name = NULL;
    long year = 0;

    while (getline(&title, &len, in) != -1)
    {
        len = 0;
        if (getline(&name, &len, in) == -1)
        {
            free(title);
            free(name);
            return READ_FILE_ERR;
        }
        if (fscanf(in, "%ld\n", &year) != 1)
        {
            free(title);
            free(name);
            return READ_FILE_ERR;
        }

        free(title);
        free(name);

        title = NULL;
        name = NULL;

        len = 0;
        file_len++;
    }
    free(title);
    *count = file_len;
    fseek(in, 0, SEEK_SET);
    return EXIT_SUCCESS;
}
int shift_cinema(cinema *dst, cinema *src)
{
    if (!dst || !src || !src->title || !src->name)
    {
        return ARG_ERR;
    }
    // char *title_tmp = NULL;
    // char *name_tmp = NULL;

    // title_tmp = strdup(src->title);
    // if (!title_tmp)
    // {
    //     return ALLOCATION_ERR;
    // }
    // name_tmp = strdup(src->name);
    // if (!name_tmp)
    // {
    //     free(title_tmp);
    //     return ALLOCATION_ERR;
    // }

    // free(dst->title);
    // free(dst->name);

    dst->title = src->title;
    dst->name = src->name;
    dst->year = src->year;

    return EXIT_SUCCESS;
}
int initialize_cinema(cinema *dst, char *title, char *name, long year)
{
    if (!dst || !title || !name)
    {
        return ARG_ERR;
    }
    char *title_tmp = NULL;
    char *name_tmp = NULL;
    
    title_tmp = strdup(title);
    if (!title_tmp)
    {
        free(title);
        free(name);
        return ALLOCATION_ERR;
    }
    name_tmp = strdup(name);
    if (!name_tmp)
    {
        free(title_tmp);
        free(title);
        free(name);
        return ALLOCATION_ERR;
    }
    dst->title = title_tmp;
    dst->name = name_tmp;
    dst->year = year;

    free(title);
    free(name);

    return EXIT_SUCCESS;
}
void print(cinema **list, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%s\n%s\n%ld\n", list[i]->title, list[i]->name, list[i]->year);
    }
}
int fill(FILE *f, cinema **list, size_t file_len, Field key)
{
    if (!f || !list || (key != TITLE && key != NAME && key != YEAR))
    {
        return ALLOCATION_ERR;
    }
    size_t len = 0;
    char *title_tmp = NULL;
    char *name_tmp = NULL;
    long year_tmp = 0;

    for (size_t i = 0; i < file_len; i++)
    {
        if (getline(&title_tmp, &len, f) == -1)
        {
            free(title_tmp);
            return ALLOCATION_ERR;
        }
        len = 0;
        if (getline(&name_tmp, &len, f) == -1)
        {
            free(title_tmp);
            free(name_tmp);
            return ALLOCATION_ERR;
        }
        if (fscanf(f, "%ld\n", &year_tmp) != 1 || year_tmp < 0)
        {
            free(title_tmp);
            free(name_tmp);
            return ALLOCATION_ERR;
        }

        title_tmp[strlen(title_tmp) - 1] = '\0';
        name_tmp[strlen(name_tmp) - 1] = '\0';
        len = 0;
        if (add_sort(title_tmp, name_tmp, year_tmp, list, key, &i))
        {
            free(title_tmp);
            free(name_tmp);
            return ALLOCATION_ERR;
        }
    }
    return EXIT_SUCCESS;
}
int add_sort(char *title, char *name, long year, cinema **list, Field key, size_t *size)
{
    size_t j = 0;
    for (size_t i = 0; i < *size; i++)
    {
        if ((key == TITLE && (strcmp(title, list[i]->title) > 0)) || (key == NAME && (strcmp(name, list[i]->name) > 0)) || (key == YEAR && ((year > list[i]->year))))
            j = i + 1;
        else if ((key == TITLE && (!strcmp(title, list[i]->title))) || (key == NAME && (!strcmp(name, list[i]->name))) || (key == YEAR && ((year == list[i]->year))))
        {
            j = i + 1;
            break;
        }
    }
    if (j == 0)
    {
        for (size_t i = *size; i > 0; i--)
        {
            if (shift_cinema(list[i], list[i - 1]))
            {
                free(title);
                free(name);
                return ALLOCATION_ERR;
            }
        }
        if (initialize_cinema(list[0], title, name, year))
        {
            return ALLOCATION_ERR;
        }
    }
    else if (j == *size)
    {
        if (initialize_cinema(list[*size], title, name, year))
        {
            return ALLOCATION_ERR;
        }
    }
    else
    {
        for (size_t i = *size; i >= j; i--)
        {
            if (shift_cinema(list[i], list[i - 1]))
            {
                free(title);
                free(name);
                return ALLOCATION_ERR;
            }
        }
        if (initialize_cinema(list[j], title, name, year))
        {
            return ALLOCATION_ERR;
        }
    }
    return EXIT_SUCCESS;
}
// int fill(FILE *f, cinema list[], size_t *size, Field key)
// {
//     /*
//     Функция fill читает из файла строки и заполняет массив структурами
//     В случае возникновения ошибки возвращает READ_STRUCT_ERROR
//     */
//     cinema tmp;
//     if (fgets(tmp.title, N + 2, f))
//     {
//         if (tmp.title[strlen(tmp.title) - 1] != '\n' || strlen(tmp.title) < 2)
//             return READ_STRUCT_ERR;
//         fgets(tmp.name, N + 2, f);
//         if (tmp.name[strlen(tmp.name) - 1] != '\n' || strlen(tmp.name) < 2)
//             return READ_STRUCT_ERR;
//         if (fscanf(f, "%ld\n", &tmp.year) != 1 || tmp.year <= 0)
//             return READ_STRUCT_ERR;
//         tmp.title[strlen(tmp.title) - 1] = '\0';
//         tmp.name[strlen(tmp.name) - 1] = '\0';
//         list[*size] = tmp;
//         *size += 1;
//         while (fgets(tmp.title, N + 2, f))
//         {
//             if (tmp.title[strlen(tmp.title) - 1] != '\n' || *size == MAX || strlen(tmp.title) < 2)
//                 return READ_STRUCT_ERR;
//             fgets(tmp.name, N + 2, f);
//             if (tmp.name[strlen(tmp.name) - 1] != '\n' || strlen(tmp.name) < 2)
//                 return READ_STRUCT_ERR;
//             if (fscanf(f, "%ld\n", &tmp.year) != 1 || tmp.year <= 0)
//                 return READ_STRUCT_ERR;
//             tmp.title[strlen(tmp.title) - 1] = '\0';
//             tmp.name[strlen(tmp.name) - 1] = '\0';
//             add_sort(&tmp, list, key, size);
//         }
//     }
//     if (!feof(f))
//         return READ_STRUCT_ERR;
//     return EXIT_SUCCESS;
// }
// void add_sort(cinema *tmp, cinema list[], Field key, size_t *size)
// {
//     /*
//     Процедура добавляет структуру tmp в упорядоченный массив cinema list
//     */
//     size_t j = 0;
//     for (size_t i = 0; i < *size; i++)
//         if ((key == TITLE && (strcmp(tmp->title, list[i].title) > 0)) || (key == NAME && (strcmp(tmp->name, list[i].name) > 0)) || (key == YEAR && ((tmp->year > list[i].year))))
//             j = i + 1;
//         else if ((key == TITLE && (!strcmp(tmp->title, list[i].title))) || (key == NAME && (!strcmp(tmp->name, list[i].name))) || (key == YEAR && ((tmp->year == list[i].year))))
//         {
//             j = i + 1;
//             break;
//         }
//     if (j == 0)
//     {
//         for (size_t i = *size; i > 0; i--)
//             list[i] = list[i - 1];
//         *list = *tmp;
//     }
//     else if (j == *size)
//         list[*size] = *tmp;
//     else
//     {
//         for (size_t i = *size; i >= j; i--)
//             list[i] = list[i - 1];
//         list[j] = *tmp;
//     }
//     *size += 1;
// }