/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** scenes
*/

#pragma once

#include "scene.h"
#include "engine.h"
#include "map_change.h"

//splashscreen
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

//spawn_map
scene_t *create_spawn_map(engine_t *engine, map_change_t *map_change);
void add_little_tree(scene_t *scn, engine_t *engine, sfVector2f pos);
void add_fence(scene_t *scn, engine_t *engine, sfVector2f pos);
void add_crates(scene_t *scn, engine_t *engine, sfVector2f pos);
void add_little_tree_snow(scene_t *scn, engine_t *engine, sfVector2f pos);
void add_npc(scene_t *scn, engine_t *engine);

//how to play
scene_t *create_scene_howtoplay(engine_t *engine);

//chara_design
scene_t *create_scene_playerdesign(engine_t *engine);
void on_start_click(engine_t *engine);
void on_next_click(engine_t *engine);
void on_previous_click(engine_t *engine);

//fight
scene_t *create_fight_map(engine_t *engine, map_change_t *map_change);
void on_sword_click(engine_t *engine);
void on_magic_click(engine_t *engine);
void on_inventory_click(engine_t *engine);
void on_escape_click(engine_t *engine);
void create_mana_player(engine_t *engine, scene_t *scn);
void create_health_player(engine_t *engine, scene_t *scn);
void update_health_player(engine_t *engine);
void update_mana_player(engine_t *engine);
void update_health_enemy(engine_t *engine);
void update_mana_enemy(engine_t *engine);
void attack_player(engine_t *engine);
void attack_sword_enemy(engine_t *engine);
void attack_magic_enemy(engine_t *engine);
void create_mana_enemy(engine_t *engine, scene_t *scn);
void create_health_enemy(engine_t *engine, scene_t *scn);
void check_end(engine_t *engine);
