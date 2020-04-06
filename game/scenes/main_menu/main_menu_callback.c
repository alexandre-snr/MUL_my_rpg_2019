/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu_callback
*/

#include "engine.h"
#include "scenes.h"

void on_play_click(engine_t *engine)
{
    snr_scene_manager_load(engine, create_scene_loadgame(engine));
}

void on_how_to_click(engine_t *engine)
{

}

void on_options_click(engine_t *engine)
{
    snr_scene_manager_load(engine, create_scene_option(engine));
}

void on_quit_click(engine_t *engine)
{
    sfRenderWindow_close(engine->win);
}