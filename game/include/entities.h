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