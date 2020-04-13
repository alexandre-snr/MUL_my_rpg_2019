/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** scene
*/

#include "scene.h"
#include "string_utils.h"
#include <stdlib.h>

scene_t *snr_scene_create(char const *name)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL)
        return (NULL);
    scene->name = name;
    scene->entities = NULL;
    scene->last_entity_id = 0;
    scene->entities_gc = malloc(sizeof(int) * 128);
    for (int i = 0; i < 128; i++)
        scene->entities_gc[i] = 0;
    scene->props = NULL;
    scene->should_free_props = 1;
    scene->loaded = 0;
    return (scene);
}

void snr_scene_init(scene_t *scene, engine_t *engine)
{
    entity_node_t *temp;

    if (scene == NULL || engine == NULL)
        return;
    temp = scene->entities;
    while (temp != NULL) {
        if (temp->it != NULL && temp->it->init != NULL)
            temp->it->init(temp->it, engine);
        temp = temp->next;
    }
    scene->loaded = 1;
}

void snr_scene_destroy(scene_t *scene, engine_t *engine)
{
    entity_node_t *temp;

    while (scene->entities != NULL) {
        if (scene->entities->it == NULL) {
            scene->entities = scene->entities->next;
            continue;
        }
        if (scene->entities->it->destroy != NULL)
            scene->entities->it->destroy(scene->entities->it, engine);
        temp = scene->entities;
        scene->entities = scene->entities->next;
        if (temp->it->data != NULL)
            free(temp->it->data);
        free(temp->it);
        free(temp);
    }
    if (scene->should_free_props && scene->props != NULL)
        free(scene->props);
    free(scene);
}

void snr_scene_update(scene_t *scene, engine_t *engine)
{
    entity_node_t *temp;

    if (scene == NULL || engine == NULL || scene->entities == NULL)
        return;
    temp = scene->entities;
    while (temp != NULL) {
        if (temp->it != NULL && temp->it->update != NULL && temp->it->enabled)
            temp->it->update(temp->it, engine);
        temp = temp->next;
    }
    snr_scene_process_gc(scene, engine);
    snr_scene_order(scene, engine);
}

void snr_scene_draw(scene_t *scene, engine_t *engine)
{
    entity_node_t *temp;

    if (scene == NULL || engine == NULL)
        return;
    temp = scene->entities;
    while (temp != NULL) {
        if (temp->it != NULL && temp->it->draw != NULL && temp->it->enabled)
            temp->it->draw(temp->it, engine);
        temp = temp->next;
    }
}
