/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** set
*/

#include "ini.h"
#include "string_utils.h"
#include <stdlib.h>

static ini_value_t *new_node(char *section, char *name, char *value)
{
    ini_value_t *new = malloc(sizeof(ini_value_t));

    if (new == NULL)
        return (NULL);
    new->section = my_strdup(section);
    new->name = my_strdup(name);
    new->value = my_strdup(value);
    new->next = NULL;
    return (new);
}

void snr_ini_set(ini_t *ini, char *section, char *name, char *value)
{
    ini_value_t *new;
    ini_value_t *new_it;

    for (ini_value_t *it = ini->values; it != NULL; it = it->next)
        if (my_streq(it->section, section) && my_streq(it->name, name)) {
            free(it->value);
            it->value = my_strdup(value);
            return;
        }
    new = new_node(section, name, value);
    if (new == NULL)
        return;
    if (ini->values == NULL) {
        ini->values = new;
        return;
    }
    for (new_it = ini->values; new_it->next != NULL; new_it = new_it->next);
    new_it->next = new;
}


