/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** obstacle
*/

#include "entities.h"
#include "entities_data.h"
#include "engine.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(obstacle);
    PR(obstacle);

    if (props->path != NULL) {
        data->texture = sfTexture_createFromFile(props->path, NULL);
        data->sprite = sfSprite_create();
        sfSprite_setTexture(data->sprite, data->texture, sfFalse);
        sfSprite_setPosition(data->sprite, props->pos);
    } else {
        data->sprite = NULL;
        data->texture = NULL;
    }
    add_collider(engine, &props->coll);
    self->data = data;
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(obstacle);

    if (data->sprite != NULL)
        sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(obstacle);

    if (data->sprite != NULL) {
        sfSprite_destroy(data->sprite);
        sfTexture_destroy(data->texture);
    }
}

entity_t *create_obstacle(char const *path, sfVector2f *pos, sfFloatRect *coll)
{
    entity_t *ent = snr_entity_create();
    entity_obstacle_props_t *pr = malloc(sizeof(entity_obstacle_props_t));

    pr->path = path;
    pr->pos = *pos;
    pr->coll = *coll;
    ent->props = pr;
    ent->init = init;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
