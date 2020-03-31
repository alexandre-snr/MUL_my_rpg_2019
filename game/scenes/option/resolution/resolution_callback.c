/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** resolution_callback
*/

#include <stdlib.h>
#include "engine.h"
#include "scenes.h"
#include "ini.h"
#include "string_convert.h"

static void change_res(int x, int y)
{
    ini_t *ini = snr_ini_load("game/assets/configs/screensize.ini");

    snr_ini_set(ini, "size", "x", itos(x, 0));
    snr_ini_set(ini, "size", "y", itos(y, 0));
    snr_ini_save(ini);
    free(ini);
}

void on_1280_click(engine_t *engine)
{
    sfVideoMode video = {1280, 766, 32};

    change_res(1280, 766);
    sfRenderWindow_destroy(engine->win);
    engine->win = sfRenderWindow_create(video, "My defender !", sfDefaultStyle,
    NULL);
    snr_scene_manager_load(engine, create_scene_resolution(engine));
}

void on_1920_click(engine_t *engine)
{
    sfVideoMode video = {1920, 1080, 32};

    change_res(1920, 1080);
    sfRenderWindow_destroy(engine->win);
    engine->win = sfRenderWindow_create(video, "My defender !", sfDefaultStyle,
    NULL);
    snr_scene_manager_load(engine, create_scene_resolution(engine));
}

void on_fullscreen_click(engine_t *engine)
{
    sfVideoMode video = {1920, 1080, 32};

    change_res(1920, 1080);
    sfRenderWindow_destroy(engine->win);
    engine->win = sfRenderWindow_create(video, "My defender !", sfFullscreen,
    NULL);
    snr_scene_manager_load(engine, create_scene_resolution(engine));
}