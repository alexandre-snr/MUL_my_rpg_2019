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
#include "rect_helper.h"
#include "vector_helper.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(player);
    PR(player);

    data->texture = sfTexture_createFromFile(props->path, NULL);
    data->pos = snr_create_vector2f(30, 30);
    data->sprite = sfSprite_create();
    data->rect = snr_create_intrect(0, 0, 32, 48);
    sfSprite_setTexture(data->sprite, data->texture, sfFalse);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    player_movement(self, engine);
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
