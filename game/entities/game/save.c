/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save
*/

#include "save.h"
#include "ini.h"
#include "engine.h"
#include "entities_data.h"
#include "inventory.h"
#include "string_convert.h"

void save(engine_t *engine)
{
    char *path = get_current_slot();
    entity_player_data_t *data = snr_scene_get_entity(engine->sm->scene,
    "Player")->data;
    ini_t *ini = snr_ini_load(path);
    int *items_nb;

    for (int i = 0; i < MAX; i++) {
        items_nb = get_inventory_item(engine, i);
        snr_ini_set(ini, "items", itos(i, 0), itos(*items_nb, 0));
    }
    snr_ini_set(ini, "position", "x", itos(data->pos.x, 0));
    snr_ini_set(ini, "position", "y", itos(data->pos.y, 0));
    snr_ini_set(ini, "position", "map", itos(SPAWN_MAP, 0));
    snr_ini_save(ini);
    snr_ini_free(ini);
}