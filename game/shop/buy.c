/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buy
*/

#include "engine.h"
#include "entities_data.h"

void buy_health_potions(engine_t *engine)
{
    entity_player_data_t *data =
    snr_scene_get_entity(engine->sm->scene, "Player")->data;

    data->inv.health_potions++;
}

void buy_mana_potions(engine_t *engine)
{
}