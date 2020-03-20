/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** string_utils2
*/

#include "string_utils.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int end = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        end = i;
    }
    end++;
    dest[end] = '\0';
    return (dest);
}

char *my_strcat(char *dest, char *src)
{
    int i;
    int j;

    j = 0;
    i = my_strlen(dest);
    while (src[j] != '\0')
        dest[i++] = src[j++];
    dest[i] = '\0';
    return (dest);
}