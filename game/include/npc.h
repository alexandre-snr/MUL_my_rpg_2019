/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** npc
*/

#pragma once

#include "engine.h"

typedef enum {
    VILLAGERS_MALE,
    VILLAGERS_FEMALE,
    DEALER
} npc_e;

char **default_talk(engine_t *engine);