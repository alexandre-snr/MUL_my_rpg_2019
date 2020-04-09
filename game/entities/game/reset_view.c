/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** reset_view
*/

#include "entities.h"
#include "engine.h"
#include "rect_helper.h"
#include <SFML/Graphics.h>

static void draw(entity_t *self, engine_t *engine)
{
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect = {0, 0, win_size.x, win_size.y};
    sfView *view = sfView_createFromRect(rect);

    sfRenderWindow_setView(engine->win, view);
}

entity_t *create_reset_view(void)
{
    entity_t *ent = snr_entity_create();

    ent->draw = draw;
    return (ent);
}
