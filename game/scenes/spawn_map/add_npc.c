/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** add_npc
*/

#include "engine.h"
#include "vector_helper.h"
#include "entities.h"
#include "npc.h"

void add_npc(scene_t *scn, engine_t *engine)
{
    sfVector2f pos = {1857, 956};

    snr_scene_add_entity(scn, engine, create_npc(VILLAGERS_MAN,
    snr_create_vector2f(1860, 963), mayor_talk), "Mayor");
}