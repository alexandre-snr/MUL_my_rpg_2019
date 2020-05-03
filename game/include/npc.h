/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** npc
*/

#pragma once

#include "engine.h"

typedef enum {
    VILLAGERS_MAN,
    VILLAGERS_WOMAN,
    DEALER
} npc_e;

char **default_talk(engine_t *engine);
char **mayor_talk(engine_t *engine);
void on_yes(engine_t *engine);
void on_no(engine_t *engine);