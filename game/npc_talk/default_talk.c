/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** default_talk
*/

#include "engine.h"
#include "string_utils.h"

char **default_talk(engine_t *engine)
{
    char **conv = malloc(sizeof(char *) * 3);

    conv[0] = my_strdup("bonjour\n");
    conv[1] = my_strdup("salope\n");
    conv[2] = NULL;
    return (conv);
}