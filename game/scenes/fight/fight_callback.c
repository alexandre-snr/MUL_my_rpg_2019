/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu_callback
*/

#include "engine.h"
#include "scenes.h"
#include "inventory.h"
#include "entities_data.h"

void on_sword_click(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Info");
    DATA(fight);

    if (data->turn == 1) {
        attack_sword_enemy(engine);
        data->turn = 0;
    }
}

void on_magic_click(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Info");
    DATA(fight);

    if (data->turn == 1) {
        attack_magic_enemy(engine);
        data->turn = 0;
    }
}

void on_inventory_click(engine_t *engine)
{
    open_inventory(engine);
}

void on_escape_click(engine_t *engine)
{
    sfRenderWindow_close(engine->win);
}
