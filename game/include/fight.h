/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#define NATURAL(x) (x < 0) ? 0 : x

typedef struct
{
    int id;
    int sword;
    int magic;
    int health;
    int mdefense;
    int defense;
    char const *path;
} enemy_quest_t;
