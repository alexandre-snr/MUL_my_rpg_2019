/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_enemy
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
    IDATA(enemy);
    PR(enemy);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfVector2f pos = {(win_size.x - (win_size.x / 6) - 38), (win_size.y / 2)};
    sfVector2f scale = {2, 2};
    map_change_t *map_change = engine->sm->scene->props;

    data->texture = sfTexture_createFromFile(props->path, NULL);
    data->pos = pos;
    data->sprite = sfSprite_create();
    data->rect = snr_create_intrect(0, 60, 19, 30);
    data->sword = 15;
    data->magic = 20;
    data->health = 100;
    data->mana = 100;
    sfSprite_setTexture(data->sprite, data->texture, sfFalse);
    sfSprite_setTextureRect(data->sprite, data->rect);
    sfSprite_setPosition(data->sprite, pos);
    sfSprite_scale(data->sprite, scale);
    self->data = data;
}

static void update(entity_t *enemy, engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Info");
    DATA(fight);

    if (data->turn == 0) {
        attack_player(engine);
        data->turn = 1;
    }
    update_mana_enemy(engine);
    update_health_enemy(engine);
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(enemy);

    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(enemy);

    sfSprite_destroy(data->sprite);
    sfTexture_destroy(data->texture);
}

entity_t *create_fight_enemy(const char *path)
{
    entity_t *ent = snr_entity_create();
    entity_enemy_props_t *pr = malloc(sizeof(entity_enemy_props_t));

    pr->path = path;
    ent->props = pr;
    ent->depth = 100;
    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
