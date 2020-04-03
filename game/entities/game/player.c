/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player
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
    IDATA(player);
    PR(player);

    data->texture = sfTexture_createFromFile(props->path, NULL);
    data->sprite = sfSprite_create();
    data->rect = snr_create_intrect(0, 0, 32, 48);
    sfSprite_setTexture(data->sprite, data->texture, sfFalse);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(player);
    sfVector2f input = {0, 0};
    float input_len = 0;

    input.x += sfKeyboard_isKeyPressed(sfKeyQ) ? -1 : 0;
    input.x += sfKeyboard_isKeyPressed(sfKeyD) ? 1 : 0;
    input.y += sfKeyboard_isKeyPressed(sfKeyZ) ? -1 : 0;
    input.y += sfKeyboard_isKeyPressed(sfKeyS) ? 1 : 0;
    input_len = snr_get_len(&input);
    if (input_len > 0) {
        input.x /= input_len;
        input.y /= input_len;
    }
    data->pos.x += input.x * 100 * engine->dt->val;
    data->pos.y += input.y * 100 * engine->dt->val;
    sfSprite_setTextureRect(data->sprite, data->rect);
    sfSprite_setPosition(data->sprite, data->pos);
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

entity_t *create_player(const char *path)
{
    entity_t *ent = snr_entity_create();
    entity_player_props_t *pr = malloc(sizeof(entity_player_props_t));

    pr->path = path;
    ent->props = pr;
    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
