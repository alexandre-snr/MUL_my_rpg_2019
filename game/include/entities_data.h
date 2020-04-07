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

typedef struct
{
    sfTexture *texture;
    sfSprite *sprite;
} entity_icon_data_t;

typedef struct
{
    char const *path;
    sfFloatRect rect;
} entity_icon_props_t;

typedef struct
{
    sfTexture *texture;
    sfSprite *sprite;
} entity_background_data_t;

typedef struct
{
    char const *path;
} entity_background_props_t;

typedef struct
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
} entity_player_data_t;

typedef struct
{
    char const *path;
} entity_player_props_t;

typedef struct
{
    sfFloatRect *colliders;
    int count;
} entity_colliders_data_t;

typedef struct
{
    sfTexture *texture;
    sfSprite *sprite;
} entity_obstacle_data_t;

typedef struct
{
    char const *path;
    sfVector2f pos;
    sfFloatRect coll;
} entity_obstacle_props_t;
