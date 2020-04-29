/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** label
*/

#include "label.h"
#include "engine.h"
#include "entity.h"
#include "vector_helper.h"
#include <SFML/Graphics/Text.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    char const *font_path = "engine/assets/fonts/Roboto-Regular.ttf";
    PR(label);
    IDATA(label);

    self->data = data;
    data->font = sfFont_createFromFile(font_path);
    data->text = sfText_create();
    data->string = props->string;
    data->rect = props->rect;
    data->size = props->size;
    data->v_align = props->v_align;
    data->h_align = props->h_align;
    data->color = props->color;
    sfText_setFont(data->text, data->font);
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(label);
    sfFloatRect rect;
    sfVector2f pos = {data->rect.left, data->rect.top};

    sfText_setString(data->text, data->string);
    sfText_setCharacterSize(data->text, data->size);
    rect = sfText_getGlobalBounds(data->text);
    if (data->h_align == CENTER)
        pos.x += (data->rect.width - rect.width) / 2;
    else if (data->h_align == RIGHT)
        pos.x += data->rect.width - rect.width;
    if (data->v_align == CENTER)
        pos.y += (data->rect.height - rect.height) / 2;
    else if (data->v_align == BOTTOM)
        pos.y += data->rect.height - rect.height;
    sfText_setColor(data->text, data->color);
    sfText_setPosition(data->text, pos);
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(label);

    sfRenderWindow_drawText(engine->win, data->text, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(label);

    sfFont_destroy(data->font);
    sfText_destroy(data->text);
}

entity_t *snr_ui_label_create(entity_label_props_t *props)
{
    entity_t *ent = snr_entity_create();

    ent->props = props;
    ent->init = init;
    ent->update = update;
    ent->depth = 10010;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
