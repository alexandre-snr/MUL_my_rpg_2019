/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** scene_depth
*/

#include "delta_time.h"
#include "entity_node.h"
#include "scene.h"

static int pass(scene_t *scene)
{
    int result = 0;
    entity_t *temp = NULL;

    for (entity_node_t *it = scene->entities; it != NULL; it = it->next) {
        if (it == NULL)
            continue;
        if (it->next != NULL &&
        (it->next->it == NULL || it->it->depth > it->next->it->depth)) {
            temp = it->it;
            it->it = it->next->it;
            it->next->it = temp;
            result = 1;
        }
    }
    return (result);
}

void snr_scene_order(scene_t *scene, engine_t *engine)
{
    while (pass(scene));
}
