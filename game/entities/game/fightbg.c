/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight background
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "engine.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(background);
    PR(background);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfVector2f scale = {(win_size.x / 1920.0), (win_size.y / 1080.0)};

    data->texture = sfTexture_createFromFile(props->path, NULL);
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->texture, sfFalse);
    sfSprite_scale(data->sprite, scale);
    self->data = data;
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(background);

    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(background);

    sfSprite_destroy(data->sprite);
    sfTexture_destroy(data->texture);
}

entity_t *create_fight_background(char const *path)
{
    entity_t *ent = snr_entity_create();
    entity_background_props_t *pr = malloc(sizeof(entity_background_props_t));

    pr->path = path;
    ent->props = pr;
    ent->depth = 1;
    ent->init = init;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
