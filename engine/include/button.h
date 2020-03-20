/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** button
*/

#pragma once

#include "entity.h"
#include <SFML/Graphics/Sprite.h>

typedef struct
{
    sfSprite *sprite;
    sfFloatRect rect;
    sfTexture *tex_normal;
    sfTexture *tex_hover;
    sfTexture *tex_pressed;
    int last_pressed;
    void (*callback)(engine_t *);
} entity_button_data_t;

typedef struct
{
    sfFloatRect rect;
    void (*callback)(engine_t *);
} entity_button_props_t;

entity_t *snr_ui_button_create(entity_button_props_t *);
