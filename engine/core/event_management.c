/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** event_management
*/

#include "scene_manager.h"

void snr_scene_manager_pevent(engine_t *engine, sfEvent *event)
{
    if (engine == NULL || event == NULL || engine->sm == NULL)
        return;
    if (engine->sm->scene == NULL)
        return;
    snr_scene_pevent(engine, engine->sm->scene, event);
}

void snr_scene_pevent(engine_t *engine, scene_t *scene, sfEvent *event)
{
    entity_node_t *temp;

    if (scene == NULL || engine == NULL || event == NULL)
        return;
    if (scene->entities == NULL)
        return;
    temp = scene->entities;
    while (temp != NULL) {
        if (temp->it == NULL) {
            temp = temp->next;
            continue;
        }
        snr_entity_pevent(temp->it, engine, event);
        temp = temp->next;
    }
}

void snr_entity_pevent(entity_t *entity, engine_t *engine, sfEvent *event)
{
    const int pevents_count = 6;
    sfEventType event_types[] = {sfEvtMouseButtonPressed,
    sfEvtMouseButtonReleased, sfEvtMouseMoved, sfEvtMouseWheelScrolled,
    sfEvtKeyPressed, sfEvtKeyReleased};
    void (*pevents[])(entity_t *, engine_t *, sfEvent *) = {
    snr_entity_pevent_mouse_down, snr_entity_pevent_mouse_up,
    snr_entity_pevent_mouse_moved, snr_entity_pevent_scroll,
    snr_entity_pevent_key_down, snr_entity_pevent_key_up};

    for (int i = 0; i < pevents_count; i++)
        if (event->type == event_types[i])
            pevents[i](entity, engine, event);
}
