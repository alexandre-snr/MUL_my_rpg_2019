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

void on_slot1_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot1.ini");
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));
    map_change_t *map_change = malloc(sizeof(map_change_t));

    map_change->map = SPAWN_MAP;
    map_change->player_pos = snr_create_vector2f(20, 20);
    if (!status) {
        snr_ini_set(ini, "status", "stat", "1");
    }
    load_map(engine, map_change);
    snr_ini_save(ini);
    snr_ini_free(ini);
}

void on_slot2_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot2.ini");
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));
    map_change_t *map_change = malloc(sizeof(map_change_t));

    map_change->map = SPAWN_MAP;
    map_change->player_pos = snr_create_vector2f(20, 20);
    if (!status) {
        snr_ini_set(ini, "status", "stat", "1");
    }
    load_map(engine, map_change);
    snr_ini_save(ini);
    snr_ini_free(ini);
}

void on_slot3_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot3.ini");
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));
    map_change_t *map_change = malloc(sizeof(map_change_t));

    map_change->map = SPAWN_MAP;
    map_change->player_pos = snr_create_vector2f(20, 20);
    if (!status) {
        snr_ini_set(ini, "status", "stat", "1");
    }
    load_map(engine, map_change);
    snr_ini_save(ini);
    snr_ini_free(ini);
}
