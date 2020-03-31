/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** win
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_win(sfWindowStyle style, sfVideoMode mode,
char const *title)
{
    sfRenderWindow *win = sfRenderWindow_create(mode, title, style, NULL);

    return (win);
}