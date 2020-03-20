/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** vector_helper
*/

#include "vector_helper.h"
#include <SFML/Graphics.h>
#include <math.h>

sfVector2f snr_create_vector2f(float x, float y)
{
    sfVector2f vec = {x, y};

    return (vec);
}

float snr_get_len(sfVector2f *vec)
{
    return (sqrt(vec->x * vec->x + vec->y * vec->y));
}

float snr_get_dist(sfVector2f *from, sfVector2f *to)
{
    sfVector2f delta = {to->x - from->x, to->y - from->y};

    return (snr_get_len(&delta));
}

sfVector2f snr_get_dir(sfVector2f *from, sfVector2f *to)
{
    sfVector2f delta = {to->x - from->x, to->y - from->y};
    float len = snr_get_len(&delta);

    if (len == 0)
        return (snr_create_vector2f(0, 0));
    return (snr_create_vector2f(delta.x / len, delta.y / len));
}
