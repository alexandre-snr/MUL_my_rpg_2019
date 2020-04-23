/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** attack
*/

#include "engine.h"
#include "scenes.h"
#include "inventory.h"
#include "entities_data.h"

void attack_player(engine_t *engine)
{
    int *health = get_inventory_item(engine, STAT_HEALTH);
    int *magicd = get_inventory_item(engine, STAT_MAGIC_DEFENSE);
    int *defense = get_inventory_item(engine, STAT_DEFENSE);
    entity_enemy_data_t *data = snr_scene_get_entity(engine->sm->scene,
    "Enemy")->data;

    if (data->magic - *magicd > data->sword - *defense)
        *health = *health - (data->magic - *magicd);
    else
        *health = *health - (data->sword - *defense);
    if (*health < 0)
        *health = 0;
}

void attack_sword_enemy(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Enemy");
    DATA(enemy);
    int *sword = get_inventory_item(engine, STAT_STRENGTH);

    data->health -= *sword;
    if (data->health < 0)
        data->health = 0;
    self->data = data;
}

void attack_magic_enemy(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Enemy");
    DATA(enemy);
    int *magic = get_inventory_item(engine, STAT_INTELLIGENCE);

    data->health -= *magic;
    if (data->health < 0)
        data->health = 0;
    self->data = data;
}
