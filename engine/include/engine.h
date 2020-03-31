/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** engine
*/

#pragma once

#include <SFML/Graphics.h>
#include "delta_time.h"

typedef struct scene_manager scene_manager_t;
typedef struct engine
{
    sfRenderWindow *win;
    struct scene_manager *sm;
    delta_time_t *dt;
} engine_t;

#include "scene_manager.h"

engine_t *snr_engine_create(char const *, sfVector2i, sfWindowStyle);
void snr_engine_run(engine_t *);
void snr_engine_destroy(engine_t *);
void snr_engine_update(engine_t *);
void snr_engine_draw(engine_t *);
sfRenderWindow *create_win(sfWindowStyle, sfVideoMode,char const *);