/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** loader
*/

#include "ini.h"
#include "string_utils.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static void parse_line(ini_t *ini, char *line, char **section)
{
    char *name;
    char *value;
    int equal_index = 0;

    if (line[0] == '[') {
        line[my_strlen(line) - 2] = 0;
        if (*section != NULL)
            free(*section);
        *section = my_strdup(line + 1);
        return;
    }
    for (; line[equal_index] && line[equal_index] != '='; equal_index++);
    name = my_strdup(line);
    name[equal_index] = 0;
    value = my_strdup(line + equal_index + 1);
    value[my_strlen(value) - 1] = 0;
    snr_ini_set(ini, *section, name, value);
    free(name);
    free(value);
}

static void load_from_file(ini_t *ini, FILE *f)
{
    char *line = NULL;
    char *section = NULL;
    size_t line_cap = 0;
    int line_len;

    while (getline(&line, &line_cap, f) >= 0) {
        line_len = my_strlen(line);
        if (line_len >= 2 && line[0] != ';')
            parse_line(ini, line, &section);
        free(line);
        line = NULL;
    }
    free(line);
    if (section != NULL)
        free(section);
}

ini_t *snr_ini_load(char const *path)
{
    ini_t *ini = malloc(sizeof(ini_t));
    FILE *f = fopen(path, "r");

    if (ini == NULL)
        return (NULL);
    if (f == NULL) {
        free(ini);
        return (NULL);
    }
    ini->path = my_strdup(path);
    ini->values = NULL;
    load_from_file(ini, f);
    fclose(f);
    return (ini);
}
