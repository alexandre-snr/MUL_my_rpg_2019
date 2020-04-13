/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** entity
*/

#include "entity.h"
#include <stdlib.h>

static void set_callback(entity_t *new)
{
    new->on_mouse_down = NULL;
    new->on_mouse_up = NULL;
    new->on_mouse_moved = NULL;
    new->on_scroll = NULL;
    new->on_key_down = NULL;
    new->on_key_up = NULL;
}

entity_t *snr_entity_create(void)
{
    entity_t *new = malloc(sizeof(entity_t));

    if (new == NULL)
        return (NULL);
    new->init = NULL;
    new->update = NULL;
    new->draw = NULL;
    new->destroy = NULL;
    new->name = "Unknown Entity";
    new->data = NULL;
    new->props = NULL;
    new->id = 0;
    new->enabled = 1;
    new->depth = 0;
    set_callback(new);
    return (new);
}

void snr_entity_destroy(entity_t *entity, engine_t *engine)
{
    if (entity->destroy)
        entity->destroy(entity, engine);
    if (entity->data)
        free(entity->data);
    if (entity->props)
        free(entity->props);
    if (entity->name)
        free(entity->name);
    free(entity);
}
