/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** update stats labels
*/

#include "label.h"
#include "label_helper.h"
#include "scene.h"
#include "scenes.h"
#include "entities.h"
#include "string_utils.h"
#include "string_convert.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void update_mana_player(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Mana");
    DATA(label);
    int *mana = get_inventory_item(engine, STAT_MANA);
    char *text;

    if (*mana == 0)
        text = my_strdup("0");
    else
        text = itos(*mana, 0);
    data->string = text;
}

void update_health_player(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Health");
    DATA(label);
    int *health = get_inventory_item(engine, STAT_HEALTH);
    char *text;

    if (*health == 0)
        text = my_strdup("0");
    else
        text = itos(*health, 0);
    data->string = text;
}

void update_mana_enemy(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Mana_enemy");
    DATA(label);
    int mana = get_mana_info(engine);
    char *text;

    if (mana == 0)
        text = my_strdup("0");
    else
        text = itos(mana, 0);
    data->string = text;
}

void update_health_enemy(engine_t *engine)
{
    entity_t *self = snr_scene_get_entity(engine->sm->scene, "Health_enemy");
    DATA(label);
    int health = get_life_info(engine);
    char *text;

    if (health == 0)
        text = my_strdup("0");
    else
        text = itos(health, 0);
    data->string = text;
}
