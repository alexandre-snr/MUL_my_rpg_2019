/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_talk_ini
*/

#include "engine.h"
#include "entities_data.h"
#include "vector_helper.h"

void init_talk(entity_t *self, engine_t *engine, int total)
{
    DATA(menu_talk);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfVector2f pos1 = {win_size.x / 2 + 40 - 300, win_size.y - 100};

    data->font =
    sfFont_createFromFile("engine/assets/fonts/Roboto-Regular.ttf");
    data->text[total] = NULL;
    data->page = 0;
    data->dt_time = 0;
    for (int i = 0; i < total; i++) {
        data->text[i] = sfText_create();
        sfText_setString(data->text[i], data->conv[i]);
        sfText_setFont(data->text[i], data->font);
        if (i % 2 == 0)
            sfText_setPosition(data->text[i], pos1);
        else
            sfText_setPosition(data->text[i],
            snr_create_vector2f(win_size.x / 2 + 40 - 300, win_size.y - 60));
    }
}