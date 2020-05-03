/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create enemy
*/

#include "delta_time.h"
#include "entities.h"
#include "entities_data.h"
#include "engine.h"
#include "entity.h"
#include "rect_helper.h"
#include "vector_helper.h"
#include "map_change.h"
#include "fight.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include <stdlib.h>

void create_enemy_list(engine_t *engine, scene_t *scn)
{

}

void init_enemy_list(engine_t *engine, scene_t *scn)
{

}

void create_enemy_quest(engine_t *engine, scene_t *scn)
{
    if (scn->props->enemy_list == NULL) {
        init_enemy_list(engine, scn);
        create_enemy_list(engine, scn);
    } else
        create_enemy_list(engine, scn);
}
