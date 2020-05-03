/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_colliders2
*/

#include "engine.h"
#include "entities.h"
#include "rect_helper.h"

static void init_6(engine_t *engine)
{
    int nb_coll = 15;
    sfFloatRect rect[] = {snr_create_floatrect(110, 1546, 115, 196),
    snr_create_floatrect(208, 1741, 61, 200),
    snr_create_floatrect(1158, 1815, 230, 10),
    snr_create_floatrect(1100, 1763, 53, 72),
    snr_create_floatrect(918, 1687, 192, 100),
    snr_create_floatrect(715, 1782, 206, 78),
    snr_create_floatrect(324, 1831, 404, 50),
    snr_create_floatrect(259, 1760, 63, 100)};

    for (int i = 0; i < nb_coll; i++)
        add_collider(engine, &rect[i]);
}

static void init_5(engine_t *engine)
{
    int nb_coll = 15;
    sfFloatRect rect[] = {snr_create_floatrect(1781, 1723, 36, 97),
    snr_create_floatrect(1613, 1722, 168, 36),
    snr_create_floatrect(1592, 1758, 10, 78),
    snr_create_floatrect(1559, 1827, 32, 32),
    snr_create_floatrect(1376, 1800, 181, 84),
    snr_create_floatrect(1214, 1322, 224, 224),
    snr_create_floatrect(945, 1444, 300, 40),
    snr_create_floatrect(900, 1321, 123, 145),
    snr_create_floatrect(894, 1007, 100, 311),
    snr_create_floatrect(655, 1008, 237, 10),
    snr_create_floatrect(680, 1013, 34, 133),
    snr_create_floatrect(659, 1140, 38, 50),
    snr_create_floatrect(610, 1201, 66, 149),
    snr_create_floatrect(338, 1368, 279, 50),
    snr_create_floatrect(147, 1418, 191, 125)};

    for (int i = 0; i < nb_coll; i++)
        add_collider(engine, &rect[i]);
    init_6(engine);
}

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
    snr_create_floatrect(1385, 1657, 100, 75),
    snr_create_floatrect(1452, 1617, 45, 45),
    snr_create_floatrect(2235, 2048, 50, 50),
    snr_create_floatrect(2058, 2066, 134, 20),
    snr_create_floatrect(1871, 1853, 20, 242),
    snr_create_floatrect(1889, 2095, 166, 10),
    snr_create_floatrect(1820, 1812, 70, 44)};

    for (int i = 0; i < nb_coll; i++)
        add_collider(engine, &rect[i]);
    init_5(engine);
}