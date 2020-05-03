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
#include "save.h"

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

void on_slot_click(char const *path, int slot, engine_t *engine)
{
    ini_t *ini = snr_ini_load(path);
    int status = stoi(*(snr_ini_get(ini, "status", "stat")));
    map_change_t *map_change;

    current_slot(slot);
    if (!status) {
        snr_scene_manager_load(engine, create_scene_playerdesign(engine));
    } else {
        map_change = malloc(sizeof(map_change_t));
        map_change->player_pos.x = stoi(*snr_ini_get(ini, "position", "x"));
        map_change->player_pos.y = stoi(*snr_ini_get(ini, "position", "y"));
        map_change->map = stoi(*snr_ini_get(ini, "position", "map"));
        map_change->selected_quest = stoi(*snr_ini_get(ini, "status", "quest"));
        map_change->enemy_one = 1;
        load_inventory(map_change);
        load_map(engine, map_change);
    }
    snr_ini_free(ini);
}

void on_slot1_click(engine_t *engine)
{
    on_slot_click("game/assets/configs/save/slot1.ini", 1, engine);
}

void on_slot2_click(engine_t *engine)
{
    on_slot_click("game/assets/configs/save/slot2.ini", 2, engine);
}

void on_slot3_click(engine_t *engine)
{
    on_slot_click("game/assets/configs/save/slot3.ini", 3, engine);
}
