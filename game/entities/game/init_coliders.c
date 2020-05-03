/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_coliders
*/

#include "engine.h"
#include "entities.h"
#include "rect_helper.h"

static void init3(engine_t *engine)
{
    int nb_coll = 15;
    sfFloatRect rect[] = {snr_create_floatrect(2197, 1695, 82, 10),
                        snr_create_floatrect(2256, 1555, 22, 141),
                        snr_create_floatrect(2380, 1576, 58, 31),
                        snr_create_floatrect(2430, 1588, 68, 68),
                        snr_create_floatrect(2498, 1570, 55, 10),
                        snr_create_floatrect(2551, 1577, 208, 30),
                        snr_create_floatrect(2889, 1540, 50, 227),
                        snr_create_floatrect(2923, 1769, 34, 150),
                        snr_create_floatrect(2861, 1917, 50, 107),
                        snr_create_floatrect(2820, 2023, 60, 189), 
                        snr_create_floatrect(2498, 2130, 96, 50),
                        snr_create_floatrect(2698, 2116, 119, 40),
                        snr_create_floatrect(2290, 2006, 131, 138),
                        snr_create_floatrect(1577, 1171, 42, 38),
                        snr_create_floatrect(1720, 1171, 42, 38)};

    for (int i = 0; i < nb_coll; i++)
        add_collider(engine, &rect[i]);
    init_4(engine);
}

static void init2(engine_t *engine)
{
    int nb_coll = 15;
    sfFloatRect rect[] = {snr_create_floatrect(2170, 1572, 77, 105),
                        snr_create_floatrect(2015, 1670, 169, 74),
                        snr_create_floatrect(1984, 1726, 25, 67),
                        snr_create_floatrect(1961, 1793, 20, 74),
                        snr_create_floatrect(1977, 1850, 62, 10),
                        snr_create_floatrect(2039, 1846, 30, 37),
                        snr_create_floatrect(2066, 1880, 67, 121),
                        snr_create_floatrect(2069, 1952, 115, 39),
                        snr_create_floatrect(2175, 1924, 10, 28),
                        snr_create_floatrect(2184, 1894, 124, 30),
                        snr_create_floatrect(2037, 1817, 72, 106),
                        snr_create_floatrect(2235, 1816, 72, 104),
                        snr_create_floatrect(2221, 1804, 26, 19),
                        snr_create_floatrect(2195, 1773, 28, 30),
                        snr_create_floatrect(2188, 1704, 10, 71)};

    for (int i = 0; i < nb_coll; i++)
        add_collider(engine, &rect[i]);
    init3(engine);
}

static void init(entity_t *self, engine_t *engine)
{

    int nb_coll = 15;
    sfFloatRect rect[] = {snr_create_floatrect(1990, 652, 350, 45),
                        snr_create_floatrect(1807, 652, 195, 315),
                        snr_create_floatrect(2513, 690, 30, 30),
                        snr_create_floatrect(2357, 690, 100, 120),
                        snr_create_floatrect(2432, 803, 191, 260),
                        snr_create_floatrect(1452, 950, 370, 230),
                        snr_create_floatrect(2327, 991, 600, 148),
                        snr_create_floatrect(2379, 1125, 109, 95),
                        snr_create_floatrect(2471, 1106, 244, 268),
                        snr_create_floatrect(2712, 1106, 115, 87),
                        snr_create_floatrect(2835, 1086, 204, 206),
                        snr_create_floatrect(2831, 1251, 108, 31),
                        snr_create_floatrect(3000, 1284, 112, 153),
                        snr_create_floatrect(2726, 1436, 266, 100),
                        snr_create_floatrect(2246, 1467, 450, 100)};

    for (int i = 0; i < nb_coll; i++)
        add_collider(engine, &rect[i]);
    init2(engine);
}

entity_t *create_init_colliders(void)
{
    entity_t *ent = snr_entity_create();

    ent->init = init;
    return (ent);
}