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
#include "vector_helper.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(info);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfVector2f pos = {win_size.x - (win_size.x / 6 + 121), win_size.y / 2 + 100};
    sfVector2f pos_two = {win_size.x - (win_size.x / 6 + 121), win_size.y / 2 + 75};

    data->txe = sfTexture_createFromFile("game/assets/sprites/health/EmptyBar.png", NULL);
    data->tx_mana = sfTexture_createFromFile("game/assets/sprites/health/BlueBar.png", NULL);
    data->tx_life = sfTexture_createFromFile("game/assets/sprites/health/RedBar.png", NULL);
    data->spe_mana = sfSprite_create();
    data->sp_mana = sfSprite_create();
    data->spe_life = sfSprite_create();
    data->sp_life = sfSprite_create();
    data->rect_life = snr_create_intrect(0, 0, 206, 28);
    data->rect_mana = snr_create_intrect(0, 0, 206, 28);
    sfSprite_setTexture(data->spe_mana, data->txe, sfFalse);
    sfSprite_setTexture(data->sp_mana, data->tx_mana, sfFalse);
    sfSprite_setTexture(data->spe_life, data->txe, sfFalse);
    sfSprite_setTexture(data->sp_life, data->tx_life, sfFalse);
    sfSprite_setPosition(data->spe_mana, pos);
    sfSprite_setPosition(data->sp_mana, pos);
    sfSprite_setPosition(data->spe_life, pos_two);
    sfSprite_setPosition(data->sp_life, pos_two);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    int health = get_life_info(engine);
    int mana = get_mana_info(engine);
    DATA(info);

    data->rect_life.width = 206.0 * (health / 100.0);
    data->rect_mana.width = 206.0 * (mana / 100.0);
    sfSprite_setTextureRect(data->sp_life, data->rect_life);
    sfSprite_setTextureRect(data->sp_mana, data->rect_mana);
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(info);

    sfRenderWindow_drawSprite(engine->win, data->spe_mana, NULL);
    sfRenderWindow_drawSprite(engine->win, data->sp_mana, NULL);
    sfRenderWindow_drawSprite(engine->win, data->spe_life, NULL);
    sfRenderWindow_drawSprite(engine->win, data->sp_life, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(info);

    sfSprite_destroy(data->spe_mana);
    sfSprite_destroy(data->sp_mana);
    sfTexture_destroy(data->tx_mana);
    sfSprite_destroy(data->spe_life);
    sfTexture_destroy(data->txe);
    sfSprite_destroy(data->sp_life);
    sfTexture_destroy(data->tx_life);
}

entity_t *create_enemy_stats(void)
{
    entity_t *ent = snr_entity_create();

    ent->depth = 100;
    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
