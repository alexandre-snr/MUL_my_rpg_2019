/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** pevent_mouse
*/

#include "entity.h"

void snr_entity_pevent_mouse_down(entity_t *ent, engine_t *eng, sfEvent *ev)
{
    if (ent->on_mouse_down != NULL)
        ent->on_mouse_down(ent, eng, &(ev->mouseButton));
}

void snr_entity_pevent_mouse_up(entity_t *ent, engine_t *eng, sfEvent *ev)
{
    if (ent->on_mouse_up != NULL)
        ent->on_mouse_up(ent, eng, &(ev->mouseButton));
}

void snr_entity_pevent_mouse_moved(entity_t *ent, engine_t *eng, sfEvent *ev)
{
    if (ent->on_mouse_moved != NULL)
        ent->on_mouse_moved(ent, eng, &(ev->mouseMove));
}

void snr_entity_pevent_scroll(entity_t *ent, engine_t *eng, sfEvent *ev)
{
    if (ent->on_scroll != NULL)
        ent->on_scroll(ent, eng, &(ev->mouseWheelScroll));
}