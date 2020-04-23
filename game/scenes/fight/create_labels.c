/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** create labels
*/

#include "label.h"
#include "label_helper.h"
#include "scene.h"
#include "scenes.h"
#include "entities.h"
#include "string_utils.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void create_mana_player(engine_t *engine, scene_t *scn)
{
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    entity_label_props_t *mana = snr_ui_label_props();
    sfFloatRect rect = {(win_size.x / 6 - 85), (win_size.y / 2) + 100, 206, 18};

    mana->color = sfWhite;
    mana->size = 10;
    mana->rect = rect;
    mana->string = my_strdup("100");
    mana->v_align = CENTER;
    mana->h_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(mana), "Mana");
}

void create_health_player(engine_t *engine, scene_t *scn)
{
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    entity_label_props_t *health = snr_ui_label_props();
    sfFloatRect rect = {(win_size.x / 6 - 85), (win_size.y / 2) + 75, 206, 18};

    health->color = sfWhite;
    health->size = 10;
    health->rect = rect;
    health->string = my_strdup("100");
    health->v_align = CENTER;
    health->h_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(health), "Health");
}

void create_mana_enemy(engine_t *engine, scene_t *scn)
{
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    entity_label_props_t *mana = snr_ui_label_props();
    sfFloatRect rect = {win_size.x - (win_size.x / 6 + 121), (win_size.y / 2) + 100, 206, 18};

    mana->color = sfWhite;
    mana->size = 10;
    mana->rect = rect;
    mana->string = my_strdup("100");
    mana->v_align = CENTER;
    mana->h_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(mana), "Mana_enemy");
}

void create_health_enemy(engine_t *engine, scene_t *scn)
{
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    entity_label_props_t *health = snr_ui_label_props();
    sfFloatRect rect = {win_size.x - (win_size.x / 6 + 121), (win_size.y / 2) + 75, 206, 18};

    health->color = sfWhite;
    health->size = 10;
    health->rect = rect;
    health->string = my_strdup("100");
    health->v_align = CENTER;
    health->h_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(health),
    "Health_enemy");
}
