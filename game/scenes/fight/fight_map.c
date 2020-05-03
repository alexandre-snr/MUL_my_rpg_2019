/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_map
*/

#include "button.h"
#include "label.h"
#include "label_helper.h"
#include "map_change.h"
#include "scene.h"
#include "scenes.h"
#include "ini.h"
#include "entities.h"
#include "string_utils.h"
#include "string_convert.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static void create_button(scene_t *scn, char const *title,
void (*callback)(engine_t *), sfFloatRect *rect)
{
    entity_button_props_t *props = malloc(sizeof(entity_button_props_t));
    entity_label_props_t *label_props = snr_ui_label_props();

    props->rect = *rect;
    props->callback = callback;
    label_props->color = sfBlack;
    label_props->size = 26;
    label_props->rect = *rect;
    label_props->string = title;
    label_props->v_align = CENTER;
    label_props->h_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_button_create(props), "Button");
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(label_props), "Label");
}

static void create_all_button(engine_t *engine, scene_t *scn)
{
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    float buttons_height = win_size.y / 2;
    int buttons_count = 4;
    float button_height = (buttons_height / buttons_count) - 20;
    sfFloatRect button_rect = {win_size.x / 10, 0, 200, button_height};
    char *labels[] = {"Sword Attack", "Magic Attack", "Inventory", "Escape"};
    void (*callbacks[])(engine_t *) = {on_sword_click, on_magic_click,
    on_inventory_click, on_escape_click};

    button_rect.top = win_size.y - (win_size.y / 6);
    for (int i = 0; i < buttons_count; i++) {
        button_rect.left = (win_size.x / buttons_count) * i + 100;
        create_button(scn, labels[i], callbacks[i], &button_rect);
    }
}

static void add_entity(scene_t *scn)
{
    ini_t *current = snr_ini_load("game/assets/configs/save/current_slot.ini");
    char *path = *snr_ini_get(current, "current", "slot");
    ini_t *ini = snr_ini_load(path);
    char *player_path = my_strdup(*snr_ini_get(ini, "skin", "path"));

    snr_scene_add_entity(scn, NULL,
    create_fight_background("game/assets/sprites/maps/fight_map.png"), "Bg");
    snr_scene_add_entity(scn, NULL, create_fight_player(player_path), "Player");
    snr_scene_add_entity(scn, NULL, create_fight_enemy(player_path), "Enemy");
    snr_scene_add_entity(scn, NULL, create_menu(), "Menu");
    snr_scene_add_entity(scn, NULL, create_fight_manager(), "Info");
    snr_scene_add_entity(scn, NULL, create_barre_stats(), "Barre");
    snr_scene_add_entity(scn, NULL, create_enemy_stats(), "Enemy_stats");
    snr_ini_free(current);
    snr_ini_free(ini);
}

scene_t *create_fight_map(engine_t *engine, map_change_t *map_change)
{
    scene_t *scn = snr_scene_create("Fight Map");

    scn->props = map_change;
    scn->should_free_props = 1;
    add_entity(scn);
    create_all_button(engine, scn);
    create_mana_player(engine, scn);
    create_health_player(engine, scn);
    create_health_enemy(engine, scn);
    return (scn);
}
