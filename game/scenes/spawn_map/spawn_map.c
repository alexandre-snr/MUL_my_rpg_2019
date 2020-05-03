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
#include "rect_helper.h"
#include "vector_helper.h"
#include <SFML/Graphics.h>

static void create_obstacles2(scene_t *scn, engine_t *engine)
{
    add_little_tree(scn, engine, snr_create_vector2f(2632, 2051));
    add_little_tree(scn, engine, snr_create_vector2f(1444, 1632));
    add_little_tree(scn, engine, snr_create_vector2f(1321, 1519));
    add_fence(scn, engine, snr_create_vector2f(2383, 2115));
    add_little_tree(scn, engine, snr_create_vector2f(2221, 1973));
    add_little_tree(scn ,engine, snr_create_vector2f(2172, 2020));
    add_little_tree(scn, engine, snr_create_vector2f(2090, 2050));
    add_little_tree(scn, engine, snr_create_vector2f(1832, 1942));
    add_little_tree(scn, engine, snr_create_vector2f(1896, 1957));
    add_little_tree(scn, engine, snr_create_vector2f(1866, 2036));
    add_little_tree(scn, engine, snr_create_vector2f(1945, 2035));
    add_little_tree(scn, engine, snr_create_vector2f(1240, 1504));
    add_little_tree(scn, engine, snr_create_vector2f(1205, 1463));
    add_crates(scn, engine, snr_create_vector2f(2026, 1189));
    add_little_tree_snow(scn, engine, snr_create_vector2f(760, 932));
    add_crates(scn, engine, snr_create_vector2f(645, 1265));
    add_fence(scn, engine, snr_create_vector2f(212, 1637));
    add_little_tree(scn, engine, snr_create_vector2f(394, 1428));
    add_little_tree(scn, engine, snr_create_vector2f(424, 1815));
    add_little_tree(scn, engine, snr_create_vector2f(479, 1815));
}

static void create_obstacles(scene_t *scn, engine_t *engine)
{
    sfVector2f pos = {2050, 610};
    sfFloatRect rect_tree1 = {2150, 930, 100, 50};
    sfVector2f house_pos = {1785, 1274};
    sfFloatRect rect_house = {1783, 1361, 322, 185};
    sfVector2f house_pos2 = {2100, 1100};
    sfFloatRect rect_house2 = {2100, 1170, 322, 195};

    snr_scene_add_entity(scn, NULL, create_obstacle(
    "game/assets/sprites/obstacles/bigtree.png", &pos, &rect_tree1), "Tree");
    snr_scene_add_entity(scn, NULL, create_obstacle(
    "game/assets/sprites/obstacles/house1.png", &house_pos, &rect_house ),
    "House");
    snr_scene_add_entity(scn, NULL, create_obstacle(
    "game/assets/sprites/obstacles/house1.png", &house_pos2, &rect_house2 ),
    "House");
    add_little_tree(scn, engine, snr_create_vector2f(2634, 1608));
    add_little_tree(scn, engine, snr_create_vector2f(2569, 2083));
    add_little_tree(scn, engine, snr_create_vector2f(2737, 2051));
    add_little_tree(scn, engine, snr_create_vector2f(2378, 1961));
    add_little_tree(scn, engine, snr_create_vector2f(2221, 1973));
    add_little_tree(scn ,engine, snr_create_vector2f(2172, 2020));
    add_little_tree(scn, engine, snr_create_vector2f(2090, 2050));
    create_obstacles2(scn, engine);
}

static void add_entity(scene_t *scn, engine_t *engine)
{
    ini_t *ini = snr_ini_load(get_current_slot());
    char *player_path = my_strdup(*snr_ini_get(ini, "skin", "path"));

    snr_scene_add_entity(scn, NULL, create_camera(), "Camera");
    snr_scene_add_entity(scn, NULL, create_colliders(), "Coll");
    snr_scene_add_entity(scn, NULL, create_init_colliders(), "Init Coll");
    snr_scene_add_entity(scn, NULL,
    create_background("game/assets/sprites/maps/Forest.png"), "Bg");
    snr_scene_add_entity(scn, NULL,
    create_player(player_path), "Player");
    create_obstacles(scn, engine);
    snr_scene_add_entity(scn, NULL, create_game_music(), "Music");
    add_npc(scn, engine);
    snr_ini_free(ini);
}

scene_t *create_spawn_map(engine_t *engine, map_change_t *map_change)
{
    scene_t *scn = snr_scene_create("Spawn Map");
    sfVector2f warp_pos = {600, 600};
    sfFloatRect warp_coll = {0, 0, 16, 1000};
    sfVector2f npc_pos = {2183, 963};

    scn->props = map_change;
    scn->should_free_props = 1;
    add_entity(scn, engine);
    snr_scene_add_entity(scn, NULL,
    create_warp(&warp_coll, SPAWN_MAP, &warp_pos), "Warp test");
    snr_scene_add_entity(scn, NULL, create_npc(DEALER, npc_pos, default_talk),
    "Marchand");
    snr_scene_add_entity(scn, NULL, create_reset_view(), "Rs");
    snr_scene_add_entity(scn, NULL, create_rain(), "Rain");
    snr_scene_add_entity(scn, NULL, create_menu(), "Menu");
    snr_scene_add_entity(scn, NULL, create_menu_answer(), "Answer");
    snr_scene_add_entity(scn, NULL, create_autosave(), "Autosave");
    snr_scene_add_entity(scn, NULL, create_current_quest(), "CQ");
    snr_scene_add_entity(scn, engine, create_menu_talk(mayor_talk), "Talk");
    return (scn);
}
