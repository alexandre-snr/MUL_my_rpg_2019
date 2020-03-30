/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** sound
*/

#include "entities.h"
#include "entities_data.h"
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(sound);
    char const *sound_path = "game/assets/splash/sound.wav";

    data->buffer = sfSoundBuffer_createFromFile(sound_path);
    data->sound = sfSound_create();
    sfSound_setBuffer(data->sound, data->buffer);
    sfSound_play(data->sound);
    self->data = data;
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(sound);

    sfSound_destroy(data->sound);
    sfSoundBuffer_destroy(data->buffer);
}

entity_t *create_entity_sound(void)
{
    entity_t *ent = snr_entity_create();

    ent->init = init;
    ent->destroy = destroy;
    return (ent);
}
