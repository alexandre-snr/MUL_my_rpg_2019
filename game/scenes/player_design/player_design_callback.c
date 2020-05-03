/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_design_callback
*/

#include <stdlib.h>
#include "engine.h"
#include "inventory.h"
#include "map_change.h"
#include "scenes.h"
#include "ini.h"
#include "entities_data.h"
#include "string_convert.h"
#include "string_utils.h"
#include "save.h"

static void init(map_change_t *map_change, ini_t *ini, engine_t * engine)
{
    inventory_t *inv  = &(map_change->inv);

    for (item_e i = 0; i < MAX; i++)
        *(extract_from_inventory(inv, i)) = 0;
    inv->health = 100;
    inv->mana = 100;
    inv->level = 1;
    map_change->player_pos.x = 2028;
    map_change->player_pos.y = 1014;
    map_change->map = SPAWN_MAP;
    map_change->selected_quest = -1;
}

void on_start_click(engine_t *engine)
{
    map_change_t *map_change = malloc(sizeof(map_change_t));
    ini_t *ini = snr_ini_load(get_current_slot());
    entity_preview_props_t *props = snr_scene_get_entity(engine->sm->scene,
    "Preview")->props;
    entity_preview_data_t *data = snr_scene_get_entity(engine->sm->scene,
    "Preview")->data;
    char *path = my_strdup(data->path_game[props->number % 4]);

    snr_ini_set(ini, "skin", "path", path);
    init(map_change, ini, engine);
    snr_ini_save(ini);
    snr_ini_free(ini);
    load_map(engine, map_change);
}

void on_next_click(engine_t *engine)
{
    entity_preview_props_t *props = snr_scene_get_entity(engine->sm->scene,
    "Preview")->props;

    if (props->number == 3)
        props->number = 0;
    else
        props->number++;
}

void on_previous_click(engine_t *engine)
{
    entity_preview_props_t *props = snr_scene_get_entity(engine->sm->scene,
    "Preview")->props;

    if (!props->number)
        props->number = 3;
    else
        props->number--;
}
