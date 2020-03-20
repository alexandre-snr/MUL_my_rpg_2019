/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** scene_get_entity
*/

#include "scene.h"
#include "string_utils.h"
#include "entity_node.h"
#include <stdlib.h>

entity_t *snr_scene_get_entity(scene_t *scene, char const *name)
{
    entity_node_t *temp;

    if (scene == NULL || name == NULL)
        return (NULL);
    temp = scene->entities;
    while (temp != NULL) {
        if (temp->it != NULL && my_streq(temp->it->name, name))
            return (temp->it);
        temp = temp->next;
    }
    return (NULL);
}