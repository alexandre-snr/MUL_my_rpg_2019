/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main
*/

#include "engine.h"
#include "scene_manager.h"
#include "scenes.h"
#include "ini.h"
#include "string_convert.h"

int main(int ac, char **av)
{
    sfVector2i size;
    engine_t *engine;
    ini_t *ini = snr_ini_load("game/assets/configs/screensize.ini");

    size.x = stoi(*snr_ini_get(ini, "size", "x"));
    size.y = stoi(*snr_ini_get(ini, "size", "y"));
    engine = snr_engine_create("My RPG !", size);
    snr_scene_manager_load(engine, create_scene_splashscreen());
    snr_engine_run(engine);
    snr_engine_destroy(engine);
    return (0);
}
