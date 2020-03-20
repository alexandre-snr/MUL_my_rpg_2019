/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** pevent_keyboard
*/

#include "entity.h"

void snr_entity_pevent_key_down(entity_t *ent, engine_t *eng, sfEvent *ev)
{
    if (ent->on_key_down != NULL)
        ent->on_key_down(ent, eng, &(ev->key));
}

void snr_entity_pevent_key_up(entity_t *ent, engine_t *eng, sfEvent *ev)
{
    if (ent->on_key_up != NULL)
        ent->on_key_up(ent, eng, &(ev->key));
}