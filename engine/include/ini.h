/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** ini
*/

#pragma once

typedef struct ini_value_s
{
    char *section;
    char *name;
    char *value;
    struct ini_value_s *next;
} ini_value_t;

typedef struct
{
    char *path;
    ini_value_t *values;
} ini_t;

ini_t *snr_ini_load(char const *);
void snr_ini_save(ini_t *);
char **snr_ini_get(ini_t *, char *, char *);
void snr_ini_set(ini_t *, char *, char *, char *);
void snr_ini_free(ini_t *);
