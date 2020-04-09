/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** entities_data
*/

#pragma once

#include "map_change.h"
#include "inventory.h"
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Graphics.h>

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
    inventory_t inv;
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

typedef struct
{
    sfFloatRect coll;
    maps_e map;
    sfVector2f player_pos;
} entity_warp_props_t;

typedef struct
{
    char *text;
} menu_entry_t;

typedef struct
{
    menu_entry_t **entries;
    int entries_count;
    int entry_selected;
    int last_key_down;
    int last_key_up;
    sfTexture *texture_panel;
    sfSprite *sprite_panel;
    sfTexture *texture_selected;
    sfSprite *sprite_selected;
    sfFont *font;
    sfText *text;
} entity_menu_data_t;
