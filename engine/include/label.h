/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** label
*/

#pragma once

#include "entity.h"
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>

typedef enum
{
    TOP, BOTTOM, CENTER, LEFT, RIGHT
} snr_label_align_e;

typedef struct
{
    sfFont *font;
    sfText *text;
    sfFloatRect rect;
    unsigned int size;
    char const *string;
    int should_display;
    snr_label_align_e v_align;
    snr_label_align_e h_align;
    sfColor color;
} entity_label_data_t;

typedef struct
{
    char const *string;
    sfFloatRect rect;
    unsigned int size;
    snr_label_align_e v_align;
    snr_label_align_e h_align;
    sfColor color;
} entity_label_props_t;

entity_t *snr_ui_label_create(entity_label_props_t *);
