/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loadgame_callback
*/

#include <stdlib.h>
#include "ini.h"
#include "engine.h"
#include "scene.h"
#include "scenes.h"
#include "string_convert.h"

void on_slot1_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot1.ini");
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));

    if (!status) {
        snr_ini_set(ini, "status", "stat", "1");
        snr_scene_manager_load(engine, create_spawn_map(engine));
    } else {
        snr_scene_manager_load(engine, create_spawn_map(engine));
    }
    snr_ini_save(ini);
    free(ini);
}

void on_slot2_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot1.ini");
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));

    if (!status) {
        snr_ini_set(ini, "status", "stat", "1");
        snr_scene_manager_load(engine, create_spawn_map(engine));
    } else {
        snr_scene_manager_load(engine, create_spawn_map(engine));
    }
    free(ini);
    snr_ini_save(ini);
}

void on_slot3_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot1.ini");
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));

    if (!status) {
        snr_ini_set(ini, "status", "stat", "1");
        snr_scene_manager_load(engine, create_spawn_map(engine));
    } else {
        snr_scene_manager_load(engine, create_spawn_map(engine));
    }
    free(ini);
    snr_ini_save(ini);
}