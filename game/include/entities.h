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
entity_t *create_warp(sfFloatRect *coll, maps_e map, sfVector2f *player_pos,
int slot_number);
