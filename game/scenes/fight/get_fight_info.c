/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "inventory.h"
#include "entities_data.h"
#include "map_change.h"
#include "scene.h"

int get_life_info(engine_t *engine)
{
    entity_enemy_data_t *p_data = snr_scene_get_entity(engine->sm->scene,
    "Enemy")->data;

    return (p_data->health);
}

void check_end(engine_t *engine)
{
    entity_player_data_t *p_data = snr_scene_get_entity(engine->sm->scene,
    "Player")->data;
    entity_enemy_data_t *e_data = snr_scene_get_entity(engine->sm->scene,
    "Enemy")->data;
    int *player = get_inventory_item(engine, STAT_HEALTH);
    int enemy = get_life_info(engine);
    map_change_t *map_change;

    if (*player <= 0 || enemy <= 0) {
        map_change = malloc(sizeof(map_change_t));
        map_change->inv = p_data->inv;
        map_change->map = e_data->map;
        map_change->player_pos = p_data->pos;
        map_change->selected_quest = p_data->selected_quest;
        load_map(engine, map_change);
    }
}
