/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** get
*/

#include "ini.h"
#include "string_utils.h"
#include <stddef.h>

char **snr_ini_get(ini_t *ini, char *section, char *name)
{
    for (ini_value_t *it = ini->values; it != NULL; it = it->next)
        if (my_streq(it->section, section) && my_streq(it->name, name))
            return (&it->value);
    return (NULL);
}
