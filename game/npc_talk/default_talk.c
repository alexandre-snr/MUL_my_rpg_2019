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
    char **conv = malloc(sizeof(char *) * 5);

    conv[0] = my_strdup("bonjour\n");
    conv[1] = my_strdup("toi\n");
    conv[2] = my_strdup("truc\n");
    conv[3] = my_strdup("test\n");
    conv[4] = NULL;
    return (conv);
}