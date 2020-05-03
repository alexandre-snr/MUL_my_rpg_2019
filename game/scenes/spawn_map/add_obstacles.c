/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** add_obstacles
*/

#include "engine.h"
#include "entities.h"

void add_little_tree(scene_t *scn, engine_t *engine, sfVector2f pos)
{
    sfFloatRect rect = {pos.x + 21, pos.y + 64,  42, 20};

    snr_scene_add_entity(scn, NULL, create_obstacle(
    "game/assets/sprites/obstacles/small_tree.png", &pos, &rect), "Tree");
}

void add_fence(scene_t *scn, engine_t *engine, sfVector2f pos)
{
    sfFloatRect rect = {pos.x, pos.y + 30, 112, 20};

    snr_scene_add_entity(scn, NULL, create_obstacle(
    "game/assets/sprites/obstacles/fence.png", &pos, &rect), "Fence");
}