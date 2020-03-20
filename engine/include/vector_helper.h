/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** vector_helper
*/

#pragma once

#include <SFML/Graphics.h>

sfVector2f snr_create_vector2f(float, float);
float snr_get_len(sfVector2f *);
float snr_get_dist(sfVector2f *, sfVector2f *);
sfVector2f snr_get_dir(sfVector2f *, sfVector2f *);
