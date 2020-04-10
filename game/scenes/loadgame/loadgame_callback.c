/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loadgame_callback
*/

#include <stdlib.h>
#include "ini.h"
#include "engine.h"
#include "map_change.h"
#include "scene.h"
#include "scenes.h"
#include "string_convert.h"
#include "vector_helper.h"
#include "string_utils.h"

static void init(ini_t *ini)
{
    snr_ini_set(ini, "status", "stat", "1");
    snr_ini_set(ini, "position", "x" , "20");
    snr_ini_set(ini, "position", "y", "20");
    snr_ini_set(ini, "position", "map", itos(SPAWN_MAP, 1));
}

static void current_slot(int number)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/current_slot.ini");
    char *path = "game/assets/configs/save/slot";
    char *end = my_strcat(itos(number, 0), ".ini");

    path = my_strcat(path, end);
    snr_ini_set(ini, "current", "slot", path);
    snr_ini_save(ini);
    snr_ini_free(ini);
}


void on_slot1_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot1.ini");
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));
    map_change_t *map_change;

    current_slot(1);
    if (!status) {
        init(ini);
        snr_scene_manager_load(engine, create_scene_playerdesign(engine));
    } else {
        map_change = malloc(sizeof(map_change_t));
        map_change->player_pos.x = stoi(*snr_ini_get(ini, "position", "x"));
        map_change->player_pos.y = stoi(*snr_ini_get(ini, "position", "y"));
        map_change->map = stoi(*snr_ini_get(ini, "position", "map"));
        map_change->inv.health_potions = 10;
        load_map(engine, map_change);
    }
    snr_ini_save(ini);
    snr_ini_free(ini);
}

void on_slot2_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot2.ini");
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));
    map_change_t *map_change = malloc(sizeof(map_change_t));

    current_slot(2);
    map_change->inv.health_potions = 10;
    if (!status) {
        init(ini);
        map_change->map = SPAWN_MAP;
        map_change->player_pos = snr_create_vector2f(20, 20);
        snr_scene_manager_load(engine, create_scene_playerdesign(engine));
    } else {
        map_change->player_pos.x = stoi(*snr_ini_get(ini, "position", "x"));
        map_change->player_pos.y = stoi(*snr_ini_get(ini, "position", "y"));
        map_change->map = stoi(*snr_ini_get(ini, "position", "map"));
        load_map(engine, map_change);
    }
    snr_ini_save(ini);
    snr_ini_free(ini);
}

void on_slot3_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot3.ini");
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));
    map_change_t *map_change = malloc(sizeof(map_change_t));

    current_slot(3);
    map_change->inv.health_potions = 10;
    if (!status) {
        init(ini);
        map_change->map = SPAWN_MAP;
        map_change->player_pos = snr_create_vector2f(20, 20);
        snr_scene_manager_load(engine, create_scene_playerdesign(engine));
    } else {
        map_change->player_pos.x = stoi(*snr_ini_get(ini, "position", "x"));
        map_change->player_pos.y = stoi(*snr_ini_get(ini, "position", "y"));
        map_change->map = stoi(*snr_ini_get(ini, "position", "map"));
        load_map(engine, map_change);
    }
    snr_ini_save(ini);
    snr_ini_free(ini);
}
