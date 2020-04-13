/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_movement
*/

#include "entities.h"
#include "entities_data.h"
#include "engine.h"
#include "vector_helper.h"

static void animation(entity_player_data_t *data, sfVector2f *in, engine_t *en)
{
    data->rect.top = in->y < 0 ? data->rect.height * 3 : data->rect.top;
    data->rect.top = in->y > 0 ? data->rect.height * 0 : data->rect.top;
    data->rect.top = in->x < 0 ? data->rect.height * 2 : data->rect.top;
    data->rect.top = in->x > 0 ? data->rect.height * 1 : data->rect.top;
    if (snr_get_len(in) == 0 || en->dt->val == 0.0f)
        data->rect.left = 0;
    else
        data->rect.left = ((int) (en->dt->since_start * 10) % 4)
        * data->rect.width;
}

static sfVector2f get_input(void)
{
    sfVector2f input = {0, 0};

    input.x += sfKeyboard_isKeyPressed(sfKeyQ) ? -1 : 0;
    input.x += sfKeyboard_isKeyPressed(sfKeyD) ? 1 : 0;
    input.y += sfKeyboard_isKeyPressed(sfKeyZ) ? -1 : 0;
    input.y += sfKeyboard_isKeyPressed(sfKeyS) ? 1 : 0;
    if (input.x != 0)
        input.y = 0;
    return (input);
}

void player_movement(entity_t *self, engine_t *engine)
{
    DATA(player);
    sfFloatRect rect = {0, 0, data->rect.width, data->rect.height / 4};
    sfVector2f input = get_input();
    const float speed = 200;

    data->pos.x += input.x * speed * engine->dt->val;
    data->pos.y += input.y * speed * engine->dt->val;
    rect.left = data->pos.x;
    rect.top = data->pos.y + data->rect.height / 2;
    if (check_colliders(engine, &rect)) {
        data->pos.x -= input.x * speed * engine->dt->val;
        data->pos.y -= input.y * speed * engine->dt->val;
    }
    animation(data, &input, engine);
    sfSprite_setTextureRect(data->sprite, data->rect);
    sfSprite_setPosition(data->sprite, data->pos);
}
