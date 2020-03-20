/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** scene_add_entity
*/

#include "scene.h"
#include "entity_node.h"

int snr_scene_add_entity(scene_t *scn, engine_t *eng, entity_t *ent, char *name)
{
    entity_node_t *entity_it;
    entity_node_t *temp;

    if (scn == NULL || ent == NULL || name == NULL)
        return (-1);
    if (scn->loaded)
        ent->init(ent, eng);
    entity_it = snr_entity_node_create(ent, name, &scn->last_entity_id);
    if (entity_it == NULL)
        return (-1);
    if (scn->entities == NULL)
        scn->entities = entity_it;
    else {
        temp = scn->entities;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = entity_it;
    }
    return (ent->id);
}