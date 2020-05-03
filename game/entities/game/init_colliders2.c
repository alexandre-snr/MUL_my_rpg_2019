/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_colliders2
*/

#include "engine.h"
#include "entities.h"
#include "rect_helper.h"

void init_4(engine_t *engine)
{
    int nb_coll = 15;
    sfFloatRect rect[] = {snr_create_floatrect(1911, 947, 83, 38),
    snr_create_floatrect(1437, 1184, 40, 40),
    snr_create_floatrect(1443, 1225, 20, 158),
    snr_create_floatrect(1465, 1383, 64, 131),
    snr_create_floatrect(1508, 1515, 20, 90),
    snr_create_floatrect(1463, 1585, 56, 39),
    snr_create_floatrect(1387, 1655, 102, 33),
    snr_create_floatrect(1296, 1528, 200, 56),
    snr_create_floatrect(1385, 1657, 100, 75)};

    for (int i = 0; i < nb_coll; i++)
        add_collider(engine, &rect[i]);
}