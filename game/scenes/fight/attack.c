/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** attack
*/

#include "engine.h"
#include "fight.h"
#include "scenes.h"
#include "inventory.h"
#include "entities_data.h"

void attack_player(engine_t *engine)
{
    int *health = get_inventory_item(engine, STAT_HEALTH);
    int *magicd = get_inventory_item(engine, STAT_MAGIC_DEFENSE);
    int *defense = get_inventory_item(engine, STAT_DEFENSE);
    int *wmagicd = get_inventory_item(engine, WSTAT_MAGIC_DEFENSE);
    int *wdefense = get_inventory_item(engine, WSTAT_DEFENSE);
    entity_enemy_data_t *data = snr_scene_get_entity(engine->sm->scene,
    "Enemy")->data;

    if (data->magic - (*magicd + *wmagicd) > data->sword - (*defense + *wdefense))
        *health -= NATURAL((data->magic - (*magicd + *wmagicd)));
    else
        *health -= NATURAL((data->sword - (*defense + *wdefense)));
    if (*health < 0)
        *health = 0;
}

void attack_sword_enemy(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Enemy");
    DATA(enemy);
    int *sword = get_inventory_item(engine, STAT_STRENGTH);
    int *wstrength = get_inventory_item(engine, WSTAT_STRENGTH);

    data->health -= NATURAL((*sword + *wstrength) - data->defense);
    if (data->health < 0)
        data->health = 0;
    self->data = data;
}

void attack_magic_enemy(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Enemy");
    DATA(enemy);
    int *magic = get_inventory_item(engine, STAT_INTELLIGENCE);
    int *wmagic = get_inventory_item(engine, WSTAT_INTELLIGENCE);

    data->health -= NATURAL((*magic + *wmagic) - data->mdefense);
    if (data->health < 0)
        data->health = 0;
    self->data = data;
}
