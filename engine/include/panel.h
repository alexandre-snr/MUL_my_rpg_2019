/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** panel
*/

#pragma once

#include "entity.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>

typedef struct
{
    sfFloatRect rect;
    sfColor color;
    sfSprite *sprite;
} entity_panel_data_t;

typedef struct
{
    sfFloatRect rect;
    sfColor color;
} entity_panel_props_t;

entity_t *snr_ui_panel_create(sfFloatRect *, sfColor *);
