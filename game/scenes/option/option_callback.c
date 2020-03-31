/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** option_callback
*/

#include "engine.h"
#include "scenes.h"

void on_resolution_click(engine_t *engine)
{
    snr_scene_manager_load(engine, create_scene_resolution(engine));
}

void on_volume_click(engine_t *engine)
{

}

void on_main_menu_click(engine_t *engine)
{
    snr_scene_manager_load(engine, create_scene_main_menu(engine));
}