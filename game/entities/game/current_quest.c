/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** current_quest
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "rect_helper.h"
#include "scene.h"
#include "vector_helper.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(current_quest);

    data->texture_panel =
    sfTexture_createFromFile("game/assets/ui/panel_beige.png", NULL);
    data->sprite_panel = sfSprite_create();
    sfSprite_setTexture(data->sprite_panel, data->texture_panel, sfFalse);
    sfSprite_setPosition(data->sprite_panel, snr_create_vector2f(10, 10));
    data->shown = 1;
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(current_quest);
    entity_player_data_t *p_data =
    snr_scene_get_entity(engine->sm->scene, "Player")->data;

    if (data->last_pressed && sfKeyboard_isKeyPressed(sfKeyJ))
        data->shown = 1;
    data->last_pressed = sfKeyboard_isKeyPressed(sfKeyJ);
    if (p_data->selected_quest == -1 || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        data->shown = 0;
        return;
    }
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(current_quest);

    if (!data->shown)
        return;
    sfRenderWindow_drawSprite(engine->win, data->sprite_panel, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(current_quest);

    sfTexture_destroy(data->texture_panel);
    sfSprite_destroy(data->sprite_panel);
}

entity_t *create_current_quest(void)
{
    entity_t *ent = snr_entity_create();

    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    ent->depth = 20000;
    return (ent);
}
