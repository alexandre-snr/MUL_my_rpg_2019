/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** colliders
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "scene.h"
#include <SFML/Graphics/Rect.h>
#include <stdlib.h>

void add_collider(engine_t *engine, sfFloatRect *rect)
{
    entity_colliders_data_t *data =
    snr_scene_get_entity(engine->sm->scene, "Coll")->data;

    data->colliders[data->count] = *rect;
    data->count++;
}

int check_colliders(engine_t *engine, sfFloatRect *rect)
{
    entity_colliders_data_t *data =
    snr_scene_get_entity(engine->sm->scene, "Coll")->data;

    for (int i = 0; i < data->count; i++)
        if (sfFloatRect_intersects(&(data->colliders[i]), rect, NULL))
            return (1);
    return (0);
}

static void init(entity_t *self, engine_t *engine)
{
    IDATA(colliders);

    data->colliders = malloc(sizeof(sfFloatRect) * 1024);
    data->count = 0;
    self->data = data;
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(colliders);

    free(data->colliders);
}

entity_t *create_colliders(void)
{
    entity_t *ent = snr_entity_create();

    ent->init = init;
    ent->destroy = destroy;
    return (ent);
}
