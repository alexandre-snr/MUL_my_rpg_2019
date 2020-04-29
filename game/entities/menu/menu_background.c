/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_background
*/

#include "engine.h"
#include "entities.h"
#include "entities_data.h"

static void init(entity_t *self, engine_t *engine)
{
    IDATA(menu_background);
    PR(menu_background);

    data->sprite = sfSprite_create();
    data->texture = sfTexture_createFromFile(props->path, NULL);
    data->tex_size.x = 1.5;
    data->tex_size.y = 1.5;
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(menu_background);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfVector2f normal = {1, 1};

    if (win_size.x >= 1920)
        sfSprite_setScale(data->sprite, data->tex_size);
    else
        sfSprite_setScale(data->sprite, normal);
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(menu_background);

    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(menu_background);

    sfSprite_destroy(data->sprite);
    sfTexture_destroy(data->texture);
}

entity_t *create_menu_background(char const *path)
{
    entity_t *ent = snr_entity_create();
    IPR(menu_background);

    pr->path = path;
    ent->depth = 1;
    ent->props = pr;
    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}