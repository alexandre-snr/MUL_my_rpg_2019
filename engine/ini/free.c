/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free
*/

#include "ini.h"
#include <stdlib.h>

void snr_ini_free(ini_t *ini)
{
    ini_value_t *it = ini->values;
    ini_value_t *next = NULL;

    while (it != NULL) {
        next = it->next;
        if (it->section != NULL)
            free(it->section);
        if (it->name != NULL)
            free(it->name);
        if (it->value != NULL)
            free(it->value);
        free(it);
        it = next;
    }
    free(ini->path);
    free(ini);
}
