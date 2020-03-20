/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** string_utils
*/

#include "string_utils.h"
#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i]; ++i);
    return (i);
}

int my_streq(char const *a, char const *b)
{
    if (!a || !b || my_strlen(a) != my_strlen(b))
        return (0);
    for (int i = 0; a[i]; i++)
        if (a[i] != b[i])
            return (0);
    return (1);
}

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *res;
    int i = 0;

    if (str == NULL)
        return (NULL);
    res = malloc(len + 1);
    for (; i < len; i++)
        res[i] = str[i];
    res[i] = 0;
    return (res);
}

char *my_strbegin(char const *str, int n)
{
    int len = my_strlen(str);
    char *res;

    if (str == NULL || n < 0)
        return (NULL);
    if (len < n)
        res = malloc(len);
    else
        res = malloc(n);
    for (int i = 0; i < n && i < len; i++)
        res[i] = str[i];
    return (res);
}

char *my_revstr(char *str)
{
    int str_len = my_strlen(str);
    char temp;

    for (int i = 0; i < str_len / 2; i++) {
        temp = str[i];
        str[i] = str[str_len - i - 1];
        str[str_len - i - 1] = temp;
    }
    return (str);
}