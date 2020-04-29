/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** entities_data
*/

#pragma once

#include "map_change.h"
#include "inventory.h"
#include "npc.h"
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
    sfVector2f old;
    sfVector2f delta;
} entity_camera_data_t;

typedef struct
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    int selected_quest;
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
    char **path;
    char **path_game;
    sfTexture **tex;
    sfSprite *chara;
    sfVector2f pos;
    sfSprite **sprite;
} entity_preview_data_t;

typedef struct
{
    int number;
} entity_preview_props_t;

typedef struct
{
    char *text;
    void (*callback)(engine_t *);
    int data;
} menu_entry_t;

typedef struct
{
    menu_entry_t **entries;
    int entries_count;
    int entry_selected;
    int last_key_down;
    int last_key_up;
    int last_key_enter;
    sfTexture *texture_panel;
    sfSprite *sprite_panel;
    sfTexture *texture_selected;
    sfSprite *sprite_selected;
    sfFont *font;
    sfText *text;
} entity_menu_data_t;

typedef struct
{
    double dt_save;
} entity_autosave_data_t;

#define RAIN_DROPS 1500
typedef struct
{
    sfVector2f drops[RAIN_DROPS];
} entity_rain_data_t;

typedef struct
{
    char **(*handler)(engine_t *);
} entity_menu_talk_props_t;

typedef struct
{
    int page;
    int total;
    int is_finish;
    int is_open;
    double dt_time;
    char **conv;
    char **(*handler)(engine_t *);
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText **text;
    sfText *name;
} entity_menu_talk_data_t;

typedef struct
{
    npc_e npc_type;
    sfVector2f pos;
    char **(*handler)(engine_t *);
} entity_npc_props_t;

typedef struct
{
    sfFloatRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    char **(*handler)(engine_t *);
} entity_npc_data_t;

typedef struct
{
    sfTexture *texture_panel;
    sfSprite *sprite_panel;
    int shown;
    int last_pressed;
    int loaded_quest;
    sfFont *fnt;
    sfText **texts;
    char **dialogs;
} entity_current_quest_data_t;

typedef struct
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f tex_size;
} entity_menu_background_data_t;

typedef struct
{
    char const *path;
} entity_menu_background_props_t;