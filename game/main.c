/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#include "engine.h"
#include "scene_manager.h"
#include "scenes.h"

int main(int ac, char **av)
{
    sfVector2i size = {1280, 766};
    engine_t *engine;

    engine = snr_engine_create("My RPG !", size);
    snr_engine_run(engine);
    snr_engine_destroy(engine);
    return (0);
}
