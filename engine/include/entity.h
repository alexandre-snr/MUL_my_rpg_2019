/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** entity
*/

#pragma once

#include <SFML/Graphics/RenderWindow.h>

#define DATA(X) entity_##X##_data_t *data = (entity_##X##_data_t *) self->data
#define IDATA(X) entity_##X##_data_t *data = malloc(sizeof(entity_##X##_data_t))
#define PR(X) entity_##X##_props_t *props = (entity_##X##_props_t *) self->props

typedef struct engine engine_t;

typedef struct entity
{
    void (*init)(struct entity *, engine_t *);
    void (*update)(struct entity *, engine_t *);
    void (*draw)(struct entity *, engine_t *);
    void (*destroy)(struct entity *, engine_t *);
    void (*on_mouse_down)(struct entity *, engine_t *, sfMouseButtonEvent *);
    void (*on_mouse_up)(struct entity *, engine_t *, sfMouseButtonEvent *);
    void (*on_mouse_moved)(struct entity *, engine_t *, sfMouseMoveEvent *);
    void (*on_scroll)(struct entity *, engine_t *, sfMouseWheelScrollEvent *);
    void (*on_key_down)(struct entity *, engine_t *, sfKeyEvent *);
    void (*on_key_up)(struct entity *, engine_t *, sfKeyEvent *);
    void *data;
    void *props;
    char *name;
    unsigned int id;
    int enabled;
} entity_t;

entity_t *snr_entity_create(void);
void snr_entity_destroy(entity_t *, engine_t *);
void snr_entity_pevent(entity_t *, engine_t *, sfEvent *);
void snr_entity_pevent_mouse_down(entity_t *, engine_t *, sfEvent *);
void snr_entity_pevent_mouse_up(entity_t *, engine_t *, sfEvent *);
void snr_entity_pevent_mouse_moved(entity_t *, engine_t *, sfEvent *);
void snr_entity_pevent_scroll(entity_t *, engine_t *, sfEvent *);
void snr_entity_pevent_key_down(entity_t *, engine_t *, sfEvent *);
void snr_entity_pevent_key_up(entity_t *, engine_t *, sfEvent *);
