/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** camera
*/

#include "entities.h"
#include "entity.h"
#include "engine.h"
#include "rect_helper.h"
#include "scene.h"
#include "vector_helper.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>

static void draw(entity_t *self, engine_t *engine)
{
    entity_player_data_t *pdata =
    snr_scene_get_entity(engine->sm->scene, "Player")->data;
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfView *view = sfView_create();

    sfView_setSize(view, snr_create_vector2f(win_size.x, win_size.y));
    sfView_setCenter(view, pdata->pos);
    sfRenderWindow_setView(engine->win, view);
}

entity_t *create_camera(void)
{
    entity_t *ent = snr_entity_create();

    ent->draw = draw;
    return (ent);
}
