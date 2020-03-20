/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** random
*/

#include <stdlib.h>
#include <time.h>

#include "random.h"

void snr_rand_init(void)
{
}

double snr_rand(double min, double max)
{
    min *= 100;
    max *= 100;
    return (min + rand() % ((int) max + 1 - (int) min)) / 100.0;
}