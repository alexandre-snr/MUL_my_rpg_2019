/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save
*/

#include <stdlib.h>
#include "save.h"
#include "ini.h"
#include "engine.h"
#include "entities_data.h"
#include "inventory.h"
#include "string_convert.h"
#include "string_utils.h"
#include "map_change.h"

void load_inventory(map_change_t *map_change)
{
    char *path = get_current_slot();
    inventory_t inv = map_change->inv;
    ini_t *ini = snr_ini_load(path);

    for (int i = 0; i < MAX; i++) {
        *extract_from_inventory(&inv, i) =
        stoi(*snr_ini_get(ini, "items", i != 0 ? itos(i, 0) :
        my_strdup("0")));
    }
    map_change->inv = inv;
    snr_ini_free(ini);
}

static void save_position(engine_t *engine, ini_t *ini)
{
    entity_player_data_t *data = snr_scene_get_entity(engine->sm->scene,
    "Player")->data;
    map_change_t *map = engine->sm->scene->props;

    snr_ini_set(ini, "position", "x",
    data->pos.x != 0 ? itos(data->pos.x, 0) : my_strdup("0"));
    snr_ini_set(ini, "position", "y",
    data->pos.y != 0 ? itos(data->pos.y, 0) : my_strdup("0"));
    snr_ini_set(ini, "position", "map",
    map->map != 0 ? itos(map->map, 0) : my_strdup("0"));
}

void save(engine_t *engine)
{
    char *path = get_current_slot();
    ini_t *ini = snr_ini_load(path);
    int **number = malloc(sizeof(int *) * 50);

    snr_ini_set(ini, "status", "stat", "1");
    for (int i = 0; i < MAX; i++) {
        number[i] = get_inventory_item(engine, i);
        snr_ini_set(ini, "items", i != 0 ? itos(i, 0) : my_strdup("0"),
        *number[i] != 0 ? itos(*number[i], 0) : my_strdup("0"));
    }
    save_position(engine, ini);
    free(path);
    free(number);
    snr_ini_save(ini);
    snr_ini_free(ini);
}
