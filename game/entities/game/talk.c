/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** talk
*/

#include "engine.h"
#include "entities_data.h"

void open_talk(engine_t *engine)
{
    entity_menu_talk_data_t *menu_data =
    snr_scene_get_entity(engine->sm->scene, "Talk")->data;

    menu_data->page = 0;
    menu_data->is_finish = 0;
    menu_data->is_open = 1;
}

void close_talk(engine_t *engine)
{
    entity_menu_talk_data_t *menu_data =
    snr_scene_get_entity(engine->sm->scene, "Talk")->data;

    menu_data->is_open = 0;
    menu_data->page = 0;
}