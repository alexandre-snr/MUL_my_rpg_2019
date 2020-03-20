/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** delta_time
*/

#include "delta_time.h"
#include <stdlib.h>

delta_time_t *snr_dt_create(void)
{
    delta_time_t *dt = malloc(sizeof(delta_time_t));

    dt->clock = sfClock_create();
    dt->current_time = 0;
    dt->previous_time = 0;
    dt->since_start = 0;
    dt->val = 0;
    return (dt);
}

void snr_dt_update(delta_time_t *dt)
{
    dt->previous_time = dt->current_time;
    dt->current_time = sfClock_getElapsedTime(dt->clock).microseconds;
    dt->since_start = dt->current_time / 1000000.0;
    dt->val = (dt->current_time - dt->previous_time) / 1000000.0;
}

void snr_dt_destroy(delta_time_t *dt)
{
    if (dt == NULL)
        return;
    sfClock_destroy(dt->clock);
    free(dt);
}