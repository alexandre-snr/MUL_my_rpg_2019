/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** scene_remove_entity
*/

#include "scene.h"
#include "entity_node.h"

void snr_scene_remove_entity(scene_t *scene, int id)
{
    entity_node_t *temp;
    int i = 0;

    if (scene == NULL || id <= 0)
        return;
    temp = scene->entities;
    while (temp != NULL) {
        if (temp->it != NULL && temp->it->id == id) {
            snr_scene_add_to_gc(scene, id);
            return;
        }
        i++;
        temp = temp->next;
    }
}

void snr_scene_add_to_gc(scene_t *scene, int i)
{
    int gc_i = 0;

    for (; scene->entities_gc[gc_i] > 0; gc_i++);
    scene->entities_gc[gc_i] = i;
}

void snr_scene_process_gc(scene_t *scene, engine_t *engine)
{
    for (int i = 0; scene->entities_gc[i] > 0; i++) {
        snr_scene_process_gc_at(scene, scene->entities_gc[i], engine);
        scene->entities_gc[i] = 0;
    }
}

void snr_scene_process_gc_at(scene_t *scene, int i, engine_t *engine)
{
    entity_node_t *temp;

    if (scene == NULL || i <= 0)
        return;
    temp = scene->entities;
    while (temp != NULL) {
        if (temp->it != NULL && temp->it->id == i) {
            snr_entity_destroy(temp->it, engine);
            temp->it = NULL;
            return;
        }
        temp = temp->next;
    }
}