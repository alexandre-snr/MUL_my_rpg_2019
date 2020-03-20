/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** entities
*/

#pragma once

#include "entity.h"

typedef struct entity_node
{
    entity_t *it;
    struct entity_node *next;
} entity_node_t;

entity_node_t *snr_entity_node_create(entity_t *, char *, int *);