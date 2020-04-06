/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** scenes
*/

#pragma once

#include "scene.h"
#include "engine.h"

scene_t *create_scene_splashscreen(void);

//main_menu
scene_t *create_scene_main_menu(engine_t *engine);
void on_play_click(engine_t *engine);
void on_how_to_click(engine_t *engine);
void on_options_click(engine_t *engine);
void on_quit_click(engine_t *engine);

//option
scene_t *create_scene_option(engine_t *engine);
void on_resolution_click(engine_t *engine);
void on_volume_click(engine_t *engine);
void on_main_menu_click(engine_t *engine);

//resolution
scene_t *create_scene_resolution(engine_t *engine);
void on_1280_click(engine_t *engine);
void on_1920_click(engine_t *engine);
void on_fullscreen_click(engine_t *engine);

//volume
scene_t *create_scene_volume(engine_t *engine);
void down_volume(engine_t *engine);
void up_volume(engine_t *engine);
void down_music_volume(engine_t *engine);
void up_music_volume(engine_t *engine);

//loadgame
scene_t *create_scene_loadgame(engine_t *engine);
void on_slot1_click(engine_t *engine);
void on_slot2_click(engine_t *engine);
void on_slot3_click(engine_t *engine);