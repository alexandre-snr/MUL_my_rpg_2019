/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#include "entities.h"
#include "entities_data.h"
#include "engine.h"
#include "entity.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(player);
    PR(player);

    data->texture = sfTexture_createFromFile(props->path, NULL);
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->texture, sfFalse);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(player);

    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(player);

    sfSprite_destroy(data->sprite);
    sfTexture_destroy(data->texture);
}

entity_t *create_player(const char *path)
{
    entity_t *ent = snr_entity_create();
    entity_player_props_t *pr = malloc(sizeof(entity_player_props_t));

    pr->path = path;
    ent->props = pr;
    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
