/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_change
*/

#include "map_change.h"
#include "scene_manager.h"
#include "scenes.h"

void load_map(engine_t *engine, map_change_t *map_change)
{
    maps_e triggers[] = {SPAWN_MAP, FIGHT_MAP, NONE_MAP};
    scene_t *(*ctors[])(engine_t *, map_change_t *) = {create_spawn_map, create_fight_map};

    for (int i = 0; triggers[i] != NONE_MAP; i++)
        if (triggers[i] == map_change->map) {
            snr_scene_manager_load(engine, ctors[i](engine, map_change));
            break;
        }
}
