/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** background
*/

#include "entities.h"
#include "entities_data.h"
#include "engine.h"
#include "vector_helper.h"
#include <stdlib.h>

void init(entity_t *self, engine_t *engine)
{
    IDATA(game_background);
    PR(game_background);

    data->texture = sfTexture_createFromFile(props->path, NULL);
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    data->tex_size = sfTexture_getSize(data->texture);
    self->data = data;
}

void draw(entity_t *self, engine_t *engine)
{
    DATA(game_background);
    PR(game_background);
    sfView *view = sfView_create();
    sfVector2f center = {data->tex_size.x / 2, data->tex_size.y / 2};
    sfVector2u ss = sfRenderWindow_getSize(engine->win);
    float ratio_tex = (float) data->tex_size.x / data->tex_size.y;
    float ratio_screen = (float) ss.x / ss.y;
    float scale = 0;

    if (ratio_screen < ratio_tex)
        scale = (float) data->tex_size.x / ss.x;
    else
        scale = (float) data->tex_size.y / ss.y;
    sfView_setCenter(view, center);
    sfView_setSize(view, snr_create_vector2f(ss.x * scale, ss.y * scale));
    sfRenderWindow_setView(engine->win, view);
    if (props->fake == 0)
        sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

void destroy(entity_t *self, engine_t *engine)
{
    DATA(game_background);

    sfSprite_destroy(data->sprite);
    sfTexture_destroy(data->texture);
}

entity_t *create_how_background(char const *path, int fake)
{
    entity_t *ent = snr_entity_create();
    entity_game_background_props_t *props =
    malloc(sizeof(entity_game_background_props_t));

    props->path = path;
    props->fake = fake;
    ent->props = props;
    ent->init = init;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
