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
#include "entities.h"

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
    map_change_t *map_change = malloc(sizeof(map_change_t));
    entity_player_data_t *p_data = snr_scene_get_entity(engine->sm->scene,
    "Player")->data;
    entity_enemy_data_t *e_data = snr_scene_get_entity(engine->sm->scene,
    "Enemy")->data;

    p_data->pos.y -= 15;
    map_change->inv = p_data->inv;
    map_change->map = e_data->map;
    map_change->player_pos = p_data->pos;
    map_change->selected_quest = p_data->selected_quest;
    map_change->enemy_one = 1;
    load_map(engine, map_change);
}
