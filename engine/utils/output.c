/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** output
*/

#include "output.h"
#include "string_utils.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_puterr(char const *str)
{
    write(2, str, my_strlen(str));
}