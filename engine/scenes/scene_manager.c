/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** scene_manager
*/

#include "scene_manager.h"
#include <stdlib.h>

scene_manager_t *snr_scene_manager_create(void)
{
    scene_manager_t *sm = malloc(sizeof(scene_manager_t));

    sm->scene = NULL;
    sm->next_scene = NULL;
    return (sm);
}

void snr_scene_manager_load(engine_t *eng, scene_t *scene)
{
    if (eng == NULL || scene == NULL)
        return;
    if (eng->sm->scene == NULL) {
        eng->sm->scene = scene;
        snr_scene_init(eng->sm->scene, eng);
    } else
        eng->sm->next_scene = scene;
}

void snr_scene_manager_update(engine_t *engine)
{
    if (engine == NULL || engine->sm->scene == NULL)
        return;
    snr_scene_update(engine->sm->scene, engine);
    if (engine->sm->next_scene != NULL) {
        snr_scene_destroy(engine->sm->scene, engine);
        engine->sm->scene = engine->sm->next_scene;
        snr_scene_init(engine->sm->scene, engine);
        engine->sm->next_scene = NULL;
        snr_scene_update(engine->sm->scene, engine);
    }
}

void snr_scene_manager_draw(engine_t *engine)
{
    if (engine == NULL || engine->sm->scene == NULL)
        return;
    snr_scene_draw(engine->sm->scene, engine);
}

void snr_scene_manager_destroy(engine_t *engine)
{
    if (engine == NULL)
        return;
    if (engine->sm->scene != NULL)
        snr_scene_destroy(engine->sm->scene, engine);
    free(engine->sm);
}
