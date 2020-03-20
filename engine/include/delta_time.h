/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** delta_time
*/

#pragma once

#include <SFML/System.h>

typedef struct delta_time
{
    sfClock *clock;
    sfInt64 current_time;
    sfInt64 previous_time;
    double since_start;
    double val;
} delta_time_t;

delta_time_t *snr_dt_create(void);
void snr_dt_update(delta_time_t *);
void snr_dt_destroy(delta_time_t *);