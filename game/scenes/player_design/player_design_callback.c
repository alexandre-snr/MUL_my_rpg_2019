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

void on_start_click(engine_t *engine)
{
    map_change_t *map_change = malloc(sizeof(map_change_t));
    ini_t *ini = snr_ini_load("game/assets/configs/save/current_slot.ini");
    entity_preview_props_t *props = snr_scene_get_entity(engine->sm->scene,
    "Preview")->props;
    entity_preview_data_t *data = snr_scene_get_entity(engine->sm->scene,
    "Preview")->data;
    char *slot = *snr_ini_get(ini, "current", "slot");
    char *path = my_strdup(data->path_game[props->number]);
    ini_t *save = snr_ini_load(slot);

    snr_ini_set(save, "skin", "path", path);
    snr_ini_save(save);
    snr_ini_free(save);
    snr_ini_free(ini);
    load_map(engine, map_change, 1);
}

void on_next_click(engine_t *engine)
{
    entity_preview_props_t *props = snr_scene_get_entity(engine->sm->scene, 
    "Preview")->props;

    props->number++;
}

void on_previous_click(engine_t *engine)
{
    entity_preview_props_t *props = snr_scene_get_entity(engine->sm->scene, 
    "Preview")->props;

    props->number--;
}