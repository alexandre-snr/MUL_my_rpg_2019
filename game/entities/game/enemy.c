/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
*/

#include "delta_time.h"
#include "entities.h"
#include "entities_data.h"
#include "engine.h"
#include "entity.h"
#include "rect_helper.h"
#include "vector_helper.h"
#include "map_change.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(enemy);
    PR(enemy);
    sfVector2f pos = {2800, 2000};
    map_change_t *map_change = engine->sm->scene->props;

    data->texture = sfTexture_createFromFile(props->path, NULL);
    data->pos = pos;
    data->sprite = sfSprite_create();
    data->rect = snr_create_intrect(0, 60, 19, 30);
    data->defense = props->defense;
    data->mdefense = props->mdefense;
    data->health = props->health;
    data->sword = props->sword;
    data->magic = props->magic;
    data->map = map_change->map;
    sfSprite_setTexture(data->sprite, data->texture, sfFalse);
    sfSprite_setTextureRect(data->sprite, data->rect);
    sfSprite_setPosition(data->sprite, pos);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    map_change_t *map_change;
    entity_player_data_t *p_data = snr_scene_get_entity(engine->sm->scene,
    "Player")->data;
    DATA(enemy);

    if (data->pos.y <= p_data->pos.y && p_data->pos.y >= data->pos.y + 10 &&
    data->pos.x > p_data->pos.x && data->pos.x - p_data->pos.x < 60) {
        map_change = malloc(sizeof(map_change_t));
        map_change->inv = p_data->inv;
        map_change->map = FIGHT_MAP;
        map_change->enemy.defense = data->defense;
        map_change->enemy.mdefense = data->mdefense;
        map_change->enemy.health = data->health;
        map_change->enemy.sword = data->sword;
        map_change->enemy.magic = data->magic;
        map_change->player_pos = p_data->pos;
        map_change->enemy.prev_map = data->map;
        map_change->selected_quest = p_data->selected_quest;
        load_map(engine, map_change);
    }
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

entity_t *create_enemy(const char *path)
{
    entity_t *ent = snr_entity_create();
    entity_enemy_props_t *pr = malloc(sizeof(entity_enemy_props_t));

    pr->defense = 1;
    pr->mdefense = 0;
    pr->health = 100;
    pr->sword = 10;
    pr->magic = 9;
    pr->path = path;
    ent->depth = 5000;
    ent->props = pr;
    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
