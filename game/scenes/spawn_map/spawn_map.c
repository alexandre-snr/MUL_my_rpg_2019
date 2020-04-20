/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** spawn_map
*/

#include "map_change.h"
#include "scene.h"
#include "scenes.h"
#include "ini.h"
#include "entities.h"
#include "string_utils.h"
#include "string_convert.h"
#include "save.h"
#include <SFML/Graphics.h>

static void add_entity(scene_t *scn)
{
    sfVector2f pos = {100, 100};
    sfFloatRect coll = {100, 110, 36, 22};
    ini_t *ini = snr_ini_load(get_current_slot());
    char *player_path = my_strdup(*snr_ini_get(ini, "skin", "path"));

    snr_scene_add_entity(scn, NULL, create_camera(), "Camera");
    snr_scene_add_entity(scn, NULL, create_colliders(), "Coll");
    snr_scene_add_entity(scn, NULL,
    create_background("game/assets/sprites/maps/spawn_map.png"), "Bg");
    snr_scene_add_entity(scn, NULL,
    create_player(player_path), "Player");
    snr_scene_add_entity(scn, NULL,
    create_obstacle("game/assets/sprites/obstacles/trunk.png", &pos, &coll),
    "Obstacle Test");
    snr_ini_free(ini);
}


scene_t *create_spawn_map(engine_t *engine, map_change_t *map_change)
{
    scene_t *scn = snr_scene_create("Spawn Map");
    sfVector2f warp_pos = {600, 600};
    sfFloatRect warp_coll = {0, 0, 16, 1000};
    sfVector2f npc_pos = {300, 300};

    scn->props = map_change;
    scn->should_free_props = 1;
    add_entity(scn);
    snr_scene_add_entity(scn, NULL,
    create_warp(&warp_coll, SPAWN_MAP, &warp_pos), "Warp test");
    snr_scene_add_entity(scn, NULL, create_npc(2, npc_pos, "Monsieur Truc"),
    "Npc");
    snr_scene_add_entity(scn, engine, create_menu_talk(default_talk, "menu"),
    "Talk");
    snr_scene_add_entity(scn, NULL, create_reset_view(), "Rs");
    snr_scene_add_entity(scn, NULL, create_rain(), "Rain");
    snr_scene_add_entity(scn, NULL, create_menu(), "Menu");
    snr_scene_add_entity(scn, NULL, create_autosave(), "Autosave");
    return (scn);
}
