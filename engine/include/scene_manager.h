/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** scene_manager
*/

#pragma once

#include "engine.h"
#include "scene.h"
typedef struct scene scene_t;

struct scene_manager
{
    scene_t *scene;
    scene_t *next_scene;
};

scene_manager_t *snr_scene_manager_create(void);
void snr_scene_manager_load(engine_t *, scene_t *);
void snr_scene_manager_update(engine_t *);
void snr_scene_manager_draw(engine_t *);
void snr_scene_manager_destroy(engine_t *);
void snr_scene_manager_pevent(engine_t *, sfEvent *);