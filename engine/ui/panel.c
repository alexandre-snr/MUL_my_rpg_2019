/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** panel
*/

#include "panel.h"
#include "entity.h"
#include "vector_helper.h"
#include "engine.h"
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(panel);
    PR(panel);

    data->rect = props->rect;
    data->color = props->color;
    data->sprite = sfSprite_create();
    self->data = data;
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(panel);
    sfImage *image = sfImage_createFromColor(
    data->rect.width, data->rect.height, data->color);
    sfTexture *tex = sfTexture_createFromImage(image, NULL);

    sfSprite_setPosition(data->sprite, snr_create_vector2f(
    data->rect.left, data->rect.top));
    sfSprite_setTexture(data->sprite, tex, sfTrue);
    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
    sfTexture_destroy(tex);
    sfImage_destroy(image);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(panel);

    sfSprite_destroy(data->sprite);
}

entity_t *snr_ui_panel_create(sfFloatRect *rect, sfColor *color)
{
    entity_t *ent = snr_entity_create();
    entity_panel_props_t *props = malloc(sizeof(entity_panel_props_t));

    props->rect = *rect;
    props->color = *color;
    ent->props = props;
    ent->init = init;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
