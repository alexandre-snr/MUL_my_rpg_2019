/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** rect_helper
*/

#include "rect_helper.h"
#include <SFML/Graphics.h>

sfFloatRect snr_create_floatrect(float top, float left, float w, float h)
{
    sfFloatRect rect = {top, left, w, h};

    return (rect);
}

sfIntRect snr_create_intrect(int top, int left, int w, int h)
{
    sfIntRect rect = {top, left, w, h};

    return (rect);
}
