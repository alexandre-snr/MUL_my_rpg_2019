/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** incon_del_callbacks
*/

#include "engine.h"
#include "ini.h"
#include "scenes.h"

void on_del1_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot1.ini");

    snr_ini_set(ini, "status", "stat", "0");
    snr_ini_save(ini);
    snr_scene_manager_load(engine, create_scene_loadgame(engine));
}

void on_del2_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot2.ini");

    snr_ini_set(ini, "status", "stat", "0");
    snr_ini_save(ini);
    snr_scene_manager_load(engine, create_scene_loadgame(engine));
}

void on_del3_click(engine_t *engine)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/slot3.ini");

    snr_ini_set(ini, "status", "stat", "0");
    snr_ini_save(ini);
    snr_scene_manager_load(engine, create_scene_loadgame(engine));
}