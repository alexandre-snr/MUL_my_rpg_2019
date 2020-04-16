/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_design_callback
*/

#include <stdlib.h>
#include "engine.h"
#include "scenes.h"
#include "ini.h"
#include "entities_data.h"
#include "string_convert.h"
#include "string_utils.h"
#include "save.h"

static void init(map_change_t *map_change, ini_t *ini, engine_t * engine)
{
    inventory_t inv  = map_change->inv;

    inv.health_potions = 10;
    inv.health = 100;
    inv.mana = 100;
    inv.level = 1;
    inv.xp = 0;
    inv.strength = 1;
    inv.intelligence = 1;
    inv.defense = 1;
    inv.magic_defense = 0;
    inv.ws_strength = 0;
    inv.ws_magic_defense = 0;
    inv.ws_intelligence = 0;
    inv.ws_defense = 0;
    map_change->inv = inv;
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
