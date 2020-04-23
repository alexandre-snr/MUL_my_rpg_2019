/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inventory
*/

#include "inventory.h"
#include "entities_data.h"
#include "scene.h"

int get_mana_info(engine_t *engine)
{
    entity_enemy_data_t *p_data = snr_scene_get_entity(engine->sm->scene,
    "Enemy")->data;

    return (p_data->mana);
}

int get_life_info(engine_t *engine)
{
    entity_enemy_data_t *p_data = snr_scene_get_entity(engine->sm->scene,
    "Enemy")->data;

    return (p_data->health);
}
