/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** entity_node
*/

#include "entity_node.h"
#include "entity.h"
#include <stdlib.h>

entity_node_t *snr_entity_node_create(entity_t *ent, char *name, int *last_id)
{
    entity_node_t *entity_it;

    entity_it = malloc(sizeof(entity_node_t));
    if (entity_it == NULL)
        return (NULL);
    entity_it->it = ent;
    entity_it->next = NULL;
    ent->name = name;
    ent->id = ++(*last_id);
    return (entity_it);
}