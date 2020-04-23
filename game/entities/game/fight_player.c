/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_player
*/

#include "entities.h"
#include "entities_data.h"
#include "engine.h"
#include "entity.h"
#include "rect_helper.h"
#include "scenes.h"
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
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfVector2f pos = {(win_size.x / 6), (win_size.y / 2)};
    sfVector2f scale = {2, 2};
    map_change_t *map_change = engine->sm->scene->props;

    data->texture = sfTexture_createFromFile(props->path, NULL);
    data->pos = pos;
    data->sprite = sfSprite_create();
    data->rect = snr_create_intrect(0, 30, 19, 30);
    sfSprite_setTexture(data->sprite, data->texture, sfFalse);
    data->inv = map_change->inv;
    sfSprite_setTextureRect(data->sprite, data->rect);
    sfSprite_setPosition(data->sprite, pos);
    sfSprite_scale(data->sprite, scale);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    update_mana_player(engine);
    update_health_player(engine);
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

entity_t *create_fight_player(const char *path)
{
    entity_t *ent = snr_entity_create();
    entity_player_props_t *pr = malloc(sizeof(entity_player_props_t));

    pr->path = path;
    ent->props = pr;
    ent->depth = 100;
    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
