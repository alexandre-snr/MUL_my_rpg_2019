/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** dealer_talk
*/

#include "engine.h"
#include "string_utils.h"

char **dealer_talk(engine_t *engine)
{
    char **conv = malloc(sizeof(char *) * 4);

    conv[0] = my_strdup("Bonjour,");
    conv[1] = my_strdup("Voulez vous acheter quelque chose ?");
    conv[2] = NULL;
    conv[3] = NULL;
    return (conv);
}