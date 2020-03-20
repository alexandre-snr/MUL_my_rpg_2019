/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** string_convert
*/

#include "string_convert.h"
#include "string_utils.h"
#include <stdlib.h>

char *itos(int val, int digits)
{
    char *res = malloc(20);
    int res_i = 0;
    char *dest_base = "0123456789";
    int dest_base_size = my_strlen(dest_base);

    for (int i = 0; i < digits; i++)
        res[i] = '0';
    res[digits] = 0;
    res[res_i++] = dest_base[val % dest_base_size];
    while (val != 0)
        res[res_i++] = dest_base[(val /= dest_base_size) % dest_base_size];
    if (digits == 0)
        res[res_i - 1] = 0;
    my_revstr(res);
    return res;
}

int stoi(char const *str)
{
    int nb = 0;
    int neg = 1;
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            neg *= -1;
    for (; str[i]; i++)
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
        } else
            break;
    return (nb * neg);
}
