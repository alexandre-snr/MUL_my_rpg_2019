/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** save
*/

#include "ini.h"
#include "string_utils.h"
#include <stdio.h>

static void print_section(char const *section, FILE *f)
{
    if (section == NULL)
        return;
    fwrite("[", 1, 1, f);
    fwrite(section, 1, my_strlen(section), f);
    fwrite("]\n", 1, 2, f);
}

static void print_entry(char const *name, char const *value, FILE *f)
{
    fwrite(name, 1, my_strlen(name), f);
    fwrite("=", 1, 1, f);
    fwrite(value, 1, my_strlen(value), f);
    fwrite("\n", 1, 1, f);
}

void snr_ini_save(ini_t *ini)
{
    FILE *f = fopen(ini->path, "w");

    if (f == NULL)
        return;
    fwrite("; snr engine\n\n", 1, 14, f);
    for (ini_value_t *it = ini->values; it != NULL; it = it->next) {
        if (it->section != NULL)
            continue;
        print_entry(it->name, it->value, f);
    }
    for (ini_value_t *it = ini->values; it != NULL; it = it->next) {
        if (it->section == NULL)
            continue;
        print_section(it->section, f);
        print_entry(it->name, it->value, f);
    }
    fclose(f);
}
