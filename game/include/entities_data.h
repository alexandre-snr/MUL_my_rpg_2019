/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** entities_data
*/

#pragma once

#include <SFML/Audio/SoundBuffer.h>

typedef struct
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    float start;
} entity_video_data_t;

typedef struct
{
    sfSoundBuffer *buffer;
    sfSound *sound;
} entity_sound_data_t;
