#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fill(FILE *f, struct cinema list[], size_t *size, size_t key)
{
    struct cinema tmp;
    if (fgets(tmp.title, N + 1, f))
    {
        if (tmp.title[strlen(tmp.title) - 1] != '\n' || strlen(tmp.title) < 2)
            return READ_STRUCT_ERR;
        fgets(tmp.name, N + 1, f);
        if (tmp.name[strlen(tmp.name) - 1] != '\n' || strlen(tmp.name) < 2)
            return READ_STRUCT_ERR;
        if (fscanf(f, "%ld\n", &tmp.year) != 1 || tmp.year < FIRST_FILM || tmp.year > LAST_FILM)
            return READ_STRUCT_ERR;
        
        list[*size] = tmp;
        *size += 1;
        size_t j;
        while (fgets(tmp.title, N + 1, f))
        {
            if (tmp.title[strlen(tmp.title) - 1] != '\n' || *size == MAX || strlen(tmp.title) < 2)
                return READ_STRUCT_ERR;
            fgets(tmp.name, N + 1, f);
            if (tmp.name[strlen(tmp.name) - 1] != '\n' || strlen(tmp.name) < 2)
                return READ_STRUCT_ERR;
            if (fscanf(f, "%ld\n", &tmp.year) != 1 || tmp.year < FIRST_FILM || tmp.year > LAST_FILM)
                return READ_STRUCT_ERR;
            j = 0;
            for (size_t i = 0; i < *size; i++)
                if ((key == TITLE && (strcmp(tmp.title, list[i].title) > 0))
                    || (key == NAME && (strcmp(tmp.name, list[i].name) > 0))
                    || (key == YEAR && ((tmp.year > list[i].year))))
                    j = i + 1;
                else if ((key == TITLE && (!strcmp(tmp.title, list[i].title)))
                    || (key == NAME && (!strcmp(tmp.name, list[i].name)))
                    || (key == YEAR && ((tmp.year == list[i].year))))
                {
                    j = i + 1;
                    break;
                }
            if (j == 0)
            {
                for (size_t i = *size; i > 0; i--)
                    list[i] = list[i - 1];
                *list = tmp;
            }
            else if (j == *size)
                list[*size] = tmp;
            else
            {
                for (size_t i = *size; i >= j; i--)
                    list[i] = list[i - 1];
                list[j] = tmp;
            }
            *size += 1;
        }
    }
    if (!feof(f))
        return READ_STRUCT_ERR;
    return EXIT_SUCCESS;
}

long bin_search(struct cinema list[], long field, char key[], size_t size)
{
    long l = 0;
    long r = size - 1;
    long mid;
    char elem[N + 1];
    switch (field)
    {
        case TITLE:
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                strncpy(elem, list[mid].title, strlen(list[mid].title) - 1);
                if (!strcmp(elem, key))
                    return mid;
                else if (strcmp(elem, key) > 0)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            return (long)NOT_FOUND;
        case NAME:
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                strncpy(elem, list[mid].name, strlen(list[mid].name) - 1);
                if (!strcmp(elem, key))
                    return mid;
                else if (strcmp(elem, key) > 0)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            return (long)NOT_FOUND;
        case YEAR:
        {
            char* check = NULL;
            long date = strtol(key, &check, 10);
            if (*check)
                return (long)KEY_ERR;
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
            return (long)NOT_FOUND;
        }
    }
    return EXIT_SUCCESS;
}

void print(struct cinema list[], size_t len)
{
    for (size_t i = 0; i < len; i++)
        printf("%s%s%ld\n", list[i].title, list[i].name, list[i].year);
}
