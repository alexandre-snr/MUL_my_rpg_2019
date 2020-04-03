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
    entity_background_data_t *bdata =
    snr_scene_get_entity(engine->sm->scene, "Bg")->data;
    sfVector2u bg_size = sfTexture_getSize(bdata->texture);
    sfVector2u w_size = sfRenderWindow_getSize(engine->win);
    sfVector2f pos = pdata->pos;
    sfView *view = sfView_create();

    pos.x = pos.x < w_size.x / 2 ? w_size.x / 2 : pos.x;
    pos.x = pos.x > bg_size.x - w_size.x / 2 ? bg_size.x - w_size.x / 2 : pos.x;
    pos.y = pos.y < w_size.y / 2 ? w_size.y / 2 : pos.y;
    pos.y = pos.y > bg_size.y - w_size.y / 2 ? bg_size.y - w_size.y / 2 : pos.y;
    sfView_setSize(view, snr_create_vector2f(w_size.x, w_size.y));
    sfView_setCenter(view, pos);
    sfRenderWindow_setView(engine->win, view);
}

entity_t *create_camera(void)
{
    entity_t *ent = snr_entity_create();

    ent->draw = draw;
    return (ent);
}
