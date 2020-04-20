/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_talk_ini
*/

#include "engine.h"
#include "entities_data.h"
#include "vector_helper.h"

static void init_talk2(entity_t *self, engine_t *engine ,int total)
{
    DATA(menu_talk);

    for (int i = 0; i < total; i++) {
        sfText_setCharacterSize(data->text[i], 20);
    }
}

void init_talk(entity_t *self, engine_t *engine, int total)
{
    DATA(menu_talk);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);

    data->font =
    sfFont_createFromFile("engine/assets/fonts/Roboto-Regular.ttf");
    data->text[total] = NULL;
    data->page = 0;
    data->dt_time = 0;
    for (int i = 0; i < total; i++) {
        data->text[i] = sfText_create();
        sfText_setString(data->text[i], data->conv[i]);
        sfText_setFont(data->text[i], data->font);
        sfText_setPosition(data->text[i],
        snr_create_vector2f(win_size.x / 2 + 40 - 300,
        win_size.y - 100 + 30 * (i % 3)));
    }
    init_talk2(self, engine, total);
}