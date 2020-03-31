/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** option_volume_callbacks
*/

#include "engine.h"
#include "ini.h"
#include "string_utils.h"
#include "string_convert.h"
#include "scenes.h"
#include <SFML/Audio/Sound.h>
#include <stdlib.h>

static void set_volume(int val, char *name, int max)
{
    ini_t *ini = snr_ini_load("game/assets/configs/volume.ini");
    char *s_val = NULL;
    int current_vol = stoi(*(snr_ini_get(ini, "volume", name)));

    current_vol += val;
    if (current_vol < 0)
        current_vol = 0;
    else if (current_vol > max)
        current_vol = max;
    s_val = current_vol == 0 ? my_strdup("0") : itos(current_vol, 0);
    *(snr_ini_get(ini, "volume", name)) = s_val;
    snr_ini_save(ini);
    snr_ini_free(ini);
}

void down_volume(engine_t *engine)
{
    set_volume(-1, "effects", 10);
    snr_scene_manager_load(engine, create_scene_volume(engine));
}

void up_volume(engine_t *engine)
{
    set_volume(1, "effects", 10);
    snr_scene_manager_load(engine, create_scene_volume(engine));
}

void down_music_volume(engine_t *engine)
{
    set_volume(-1, "music", 20);
    snr_scene_manager_load(engine, create_scene_volume(engine));
}

void up_music_volume(engine_t *engine)
{
    set_volume(1, "music", 20);
    snr_scene_manager_load(engine, create_scene_volume(engine));
}
