/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "inventory.h"
#include "entities_data.h"
#include "scene.h"
#include "string_utils.h"
#include "string_convert.h"
#include "ini.h"
#include <stdlib.h>

int *extract_from_inventory(inventory_t *inv, item_e item)
{
    return ((int *) ((void *) inv + item * sizeof(int)));
}

int *get_inventory_item(engine_t *engine, item_e item)
{
    entity_player_data_t *p_data = snr_scene_get_entity(engine->sm->scene,
    "Player")->data;
    inventory_t *inv = &(p_data->inv);

    return (extract_from_inventory(inv, item));
}

int is_inventory_item_player_stat(item_e item)
{
    item_e triggers[] = {STAT_HEALTH, STAT_MANA, STAT_LEVEL, STAT_XP,
    STAT_STRENGTH, STAT_INTELLIGENCE, STAT_DEFENSE, STAT_MAGIC_DEFENSE,
    WSTAT_STRENGTH, WSTAT_INTELLIGENCE, WSTAT_DEFENSE, WSTAT_MAGIC_DEFENSE,
    MAX};

    for (int i = 0; triggers[i] != MAX; i++)
        if (triggers[i] == item)
            return (1);
    return (0);

}

char const *get_inventory_item_name(item_e item)
{
    ini_t *ini = snr_ini_load("game/assets/configs/items.ini");
    char *name = item != 0 ? itos(item, 0) : my_strdup("0");
    char *result = my_strdup(*snr_ini_get(ini, name, "name"));

    snr_ini_free(ini);
    free(name);
    return (result);
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
