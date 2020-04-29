/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** entities
*/

#pragma once

#include "entity.h"
#include "entities_data.h"

entity_t *create_entity_video(void);
entity_t *create_entity_sound(void);
entity_t *create_icon(char const *path, sfFloatRect *rect);
entity_t *create_background(char const *path);
entity_t *create_player(const char *path);
void player_movement(entity_t *self, engine_t *engine);
entity_t *create_camera(void);
entity_t *create_colliders(void);
void add_collider(engine_t *engine, sfFloatRect *rect);
int check_colliders(engine_t *engine, sfFloatRect *rect);
entity_t *create_obstacle(char const *path, sfVector2f *pos, sfFloatRect *coll);
entity_t *create_warp(sfFloatRect *coll, maps_e map, sfVector2f *player_pos);
entity_t *create_preview(int number);
entity_t *create_menu(void);
void menu_update(entity_t *self, engine_t *engine);
void open_main_menu(engine_t *engine, int bypass_key);
void close_menu(engine_t *engine);
void open_inventory(engine_t *engine);
void open_stats(engine_t *engine);
void open_quests(engine_t *engine);
void open_menu(engine_t *engine, menu_entry_t **entries);
entity_t *create_reset_view(void);
entity_t *create_autosave(void);
entity_t *create_rain(void);
void init_talk(entity_t *self, engine_t *engine, int total);
entity_t *create_menu_talk(char **(*handler)(engine_t *));
entity_t *create_npc(npc_e npc_type, sfVector2f pos,
char **(handler)(engine_t *));
void close_talk(engine_t *engine);
void open_talk(engine_t *engine, char **(*handler)(engine_t *));
entity_t *create_current_quest(void);
void menu_answer_update(entity_t *self, engine_t *engine);
void close_menu_answer(engine_t *engine);
void open_menu_answer(engine_t *engine, menu_entry_t **entries);
entity_t *create_menu_answer(void);
void open_menu_ans(engine_t *engine);
entity_t *create_menu_background(char const *path);
