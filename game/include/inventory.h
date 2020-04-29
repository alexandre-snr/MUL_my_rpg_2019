/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#pragma once

#include "engine.h"

typedef struct
{
    int health;
    int mana;
    int level;
    int xp;
    int strength;
    int intelligence;
    int defense;
    int magic_defense;
    int ws_strength;
    int ws_intelligence;
    int ws_defense;
    int ws_magic_defense;
    int health_potions;
    int quest_hello;
} inventory_t;

typedef enum
{
    STAT_HEALTH,
    STAT_MANA,
    STAT_LEVEL,
    STAT_XP,
    STAT_STRENGTH,
    STAT_INTELLIGENCE,
    STAT_DEFENSE,
    STAT_MAGIC_DEFENSE,
    WSTAT_STRENGTH,
    WSTAT_INTELLIGENCE,
    WSTAT_DEFENSE,
    WSTAT_MAGIC_DEFENSE,
    HEALTH_POTION,
    QUEST_HELLO,
    MAX
} item_e;

typedef enum
{
    STAT,
    OBJECT,
    QUEST
} item_type_e;

int *extract_from_inventory(inventory_t *inv, item_e item);
int *get_inventory_item(engine_t *engine, item_e item);
item_type_e get_inventory_item_type(item_e item);
char *get_inventory_item_name(item_e item);
void *get_inventory_item_use(item_e item);
int get_life_info(engine_t *engine);
int get_mana_info(engine_t *engine);

void health_potion_use(engine_t *engine);
