/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** health_potion
*/

#include "inventory.h"

void health_potion_use(engine_t *engine)
{
    (*get_inventory_item(engine, HEALTH_POTION))--;
}
