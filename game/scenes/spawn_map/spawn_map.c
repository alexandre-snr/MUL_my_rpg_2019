/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** spawn_map
*/

#include "map_change.h"
#include "scene.h"
#include "scenes.h"
#include "entities.h"
#include <SFML/Graphics.h>

scene_t *create_spawn_map(engine_t *engine, map_change_t *map_change)
{
    scene_t *scn = snr_scene_create("Spawn Map");
    sfVector2f pos = {100, 100};
    sfFloatRect coll = {100, 100, 36, 32};
    sfVector2f warp_pos = {600, 600};
    sfFloatRect warp_coll = {0, 0, 16, 1000};

    scn->props = map_change;
    scn->should_free_props = 1;
    snr_scene_add_entity(scn, NULL, create_camera(), "Camera");
    snr_scene_add_entity(scn, NULL, create_colliders(), "Coll");
    snr_scene_add_entity(scn, NULL,
    create_background("game/assets/sprites/maps/spawn_map.png"), "Bg");
    snr_scene_add_entity(scn, NULL,
    create_player("game/assets/sprites/players/0.png"), "Player");
    snr_scene_add_entity(scn, NULL,
    create_obstacle("game/assets/sprites/obstacles/trunk.png", &pos, &coll),
    "Obstacle Test");
    snr_scene_add_entity(scn, NULL,
    create_warp(&warp_coll, SPAWN_MAP, &warp_pos), "Warp test");
    return (scn);
}
