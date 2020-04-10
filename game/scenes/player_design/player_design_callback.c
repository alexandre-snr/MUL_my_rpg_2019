/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_design_callback
*/

#include <stdlib.h>
#include "engine.h"
#include "scenes.h"
#include "entities_data.h"

void on_start_click(engine_t *engine)
{
    map_change_t *map_change = malloc(sizeof(map_change_t));

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