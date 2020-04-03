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
    if (in->y < 0)
        data->rect.top = data->rect.height * 3;
    if (in->y > 0)
        data->rect.top = data->rect.height * 0;
    if (in->x < 0)
        data->rect.top = data->rect.height * 2;
    if (in->x > 0)
        data->rect.top = data->rect.height * 1;
    if (snr_get_len(in) == 0)
        data->rect.left = 0;
    else
        data->rect.left = ((int) (en->dt->since_start * 10) % 4)
        * data->rect.width;
}

void player_movement(entity_t *self, engine_t *engine)
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
    data->pos.x += input.x * 200 * engine->dt->val;
    data->pos.y += input.y * 200 * engine->dt->val;
    animation(data, &input, engine);
    sfSprite_setTextureRect(data->sprite, data->rect);
    sfSprite_setPosition(data->sprite, data->pos);

}
