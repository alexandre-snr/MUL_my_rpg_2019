/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_change
*/

#pragma once

#include "engine.h"
#include "inventory.h"
#include <SFML/System/Vector2.h>

typedef enum
{
    SPAWN_MAP,
    FIGHT_MAP,
    NONE_MAP
} maps_e;

typedef struct
{
    int sword;
    int magic;
    int health;
    int mana;
    char *enemy_path;
} enemy_info_t;

typedef struct
{
    sfVector2f player_pos;
    maps_e map;
    inventory_t inv;
    enemy_info_t enemy;
    int selected_quest;
} map_change_t;

void load_map(engine_t *engine, map_change_t *map_change);
