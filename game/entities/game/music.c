/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** music
*/

#include "entities.h"
#include "entities_data.h"
#include "ini.h"
#include "string_convert.h"
#include <SFML/Audio.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(game_music);
    ini_t *ini = snr_ini_load("game/assets/configs/volume.ini");
    int volume = stoi(*(snr_ini_get(ini, "volume", "music")));

    data->music = sfMusic_createFromFile("game/assets/music/music.ogg");
    sfMusic_setLoop(data->music, sfTrue);
    sfMusic_setVolume(data->music, volume);
    data->fight = sfMusic_createFromFile("game/assets/music/fight.ogg");
    sfMusic_setLoop(data->music, sfTrue);
    sfMusic_setVolume(data->music, volume);
    snr_ini_free(ini);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(game_music);
    map_change_t *map_change = engine->sm->scene->props;

    if (map_change->map == SPAWN_MAP && !data->is_running) {
        sfMusic_play(data->music);
        data->is_running = 1;
    } else if (map_change->map == FIGHT_MAP && !data->is_running) {
        sfMusic_play(data->fight);
        data->is_running = 1;
    }
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(game_music);

    sfMusic_destroy(data->music);
    sfMusic_destroy(data->fight);
}

entity_t *create_game_music(void)
{
    entity_t *ent = snr_entity_create();

    ent->init = init;
    ent->destroy = destroy;
    ent->update = update;
    return (ent);
}
