/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** icon
*/

#include "entities.h"
#include "entities_data.h"
#include "vector_helper.h"
#include "engine.h"
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(icon);
    PR(icon);
    sfVector2u tex_size;
    sfVector2f scale;

    data->texture = sfTexture_createFromFile(props->path, NULL);
    tex_size = sfTexture_getSize(data->texture);
    scale.x = props->rect.width / tex_size.x;
    scale.y = props->rect.height / tex_size.y;
    data->sprite = sfSprite_create();
    sfSprite_setScale(data->sprite, scale);
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    sfSprite_setPosition(data->sprite,
    snr_create_vector2f(props->rect.left, props->rect.top));
    self->data = data;
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(icon);

    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(icon);

    sfSprite_destroy(data->sprite);
    sfTexture_destroy(data->texture);
}

entity_t *create_icon(char const *path, sfFloatRect *rect)
{
    entity_t *ent = snr_entity_create();
    entity_icon_props_t *props = malloc(sizeof(entity_icon_props_t));

    props->path = path;
    props->rect = *rect;
    ent->props = props;
    ent->depth = 10010;
    ent->init = init;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
