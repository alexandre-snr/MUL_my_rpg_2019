/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save
*/

#pragma once

#include "engine.h"
#include "map_change.h"

char *get_current_slot(void);
void save(engine_t *engine);
void load_inventory(map_change_t *map_change);