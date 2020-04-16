/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "inventory.h"
#include "entities_data.h"
#include "scene.h"

int *get_inventory_item(engine_t *engine, item_e item)
{
    entity_player_data_t *p_data = snr_scene_get_entity(engine->sm->scene,
    "Player")->data;
    item_e triggers[] = {STAT_HEALTH, STAT_MANA, STAT_LEVEL, STAT_XP,
    STAT_STRENGTH, STAT_INTELLIGENCE, STAT_DEFENSE, STAT_MAGIC_DEFENSE,
    HEALTH_POTION, MAX};
    int *results[] = {&p_data->inv.health, &p_data->inv.mana,
    &p_data->inv.level, &p_data->inv.xp, &p_data->inv.strength,
    &p_data->inv.intelligence, &p_data->inv.defense, &p_data->inv.magic_defense,
    &p_data->inv.health_potions};

    for (int i = 0; triggers[i] != MAX; i++)
        if (triggers[i] == item)
            return (results[i]);
    return (NULL);
}

int is_inventory_item_player_stat(item_e item)
{
    item_e triggers[] = {STAT_HEALTH, STAT_MANA, STAT_LEVEL, STAT_XP,
    STAT_STRENGTH, STAT_INTELLIGENCE, STAT_DEFENSE, STAT_MAGIC_DEFENSE, MAX};

    for (int i = 0; triggers[i] != MAX; i++)
        if (triggers[i] == item)
            return (1);
    return (0);

}

char const *get_inventory_item_name(item_e item)
{
    item_e triggers[] = {STAT_HEALTH, STAT_MANA, STAT_LEVEL, STAT_XP,
    STAT_STRENGTH, STAT_INTELLIGENCE, STAT_DEFENSE, STAT_MAGIC_DEFENSE,
    HEALTH_POTION, MAX};
    char const *results[] = {"Vie", "Mana", "Niveau", "Experience", "Force",
    "Intelligence", "Defense", "Defense magique", "Potion de vie"};

    for (int i = 0; triggers[i] != MAX; i++)
        if (triggers[i] == item)
            return (results[i]);
    return (NULL);
}

void *get_inventory_item_use(item_e item)
{
    item_e triggers[] = {HEALTH_POTION, MAX};
    void *results[] = {health_potion_use};

    for (int i = 0; triggers[i] != MAX; i++)
        if (triggers[i] == item)
            return (results[i]);
    return (NULL);
}
