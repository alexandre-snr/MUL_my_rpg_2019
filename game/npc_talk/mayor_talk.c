/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mayor_talk
*/

#include "engine.h"
#include "entities_data.h"
#include "string_utils.h"
#include <stdlib.h>

char **mayor_talk(engine_t *engine)
{
    char **conv = malloc(sizeof(char *) * 6);

    conv[0] = my_strdup("Bonjour, jeune aventurier nous sommes de plus");
    conv[1] = my_strdup("en plus attaque par des brigands, serait-il");
    conv[2] = my_strdup("possible de nous venir en aide ?");
    conv[3] = my_strdup("D'apres des villageois il aurait etabli un camp");
    conv[4] = my_strdup("au nord-ouest du village.");
    conv[5] = NULL;
    return (conv);
}