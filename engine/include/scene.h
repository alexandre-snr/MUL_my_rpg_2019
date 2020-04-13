/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** scene
*/

#pragma once

#include "engine.h"
#include "entity_node.h"
#include "entity.h"

typedef struct scene
{
    char const *name;
    entity_node_t *entities;
    int last_entity_id;
    int *entities_gc;
    void *props;
    int should_free_props;
    int loaded;
} scene_t;

scene_t *snr_scene_create(char const *);
void snr_scene_init(scene_t *, engine_t *);
void snr_scene_destroy(scene_t *, engine_t *);
int snr_scene_add_entity(scene_t *, engine_t *, entity_t *, char *);
void snr_scene_remove_entity(scene_t *, int);
void snr_scene_add_to_gc(scene_t *, int);
void snr_scene_process_gc(scene_t *, engine_t *);
void snr_scene_process_gc_at(scene_t *, int, engine_t *);
entity_t *snr_scene_get_entity(scene_t *, char const *);
void snr_scene_update(scene_t *, engine_t *);
void snr_scene_pevent(engine_t *, scene_t *, sfEvent *);
void snr_scene_draw(scene_t *, engine_t *);
void snr_scene_order(scene_t *scene, engine_t *engine);
