/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** video
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "engine.h"
#include "scene_manager.h"
#include "scenes.h"
#include "vector_helper.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(video);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    char const *video_path = "game/assets/splash/video.png";

    data->rect.width = 100;
    data->rect.height = 56;
    data->texture = sfTexture_createFromFile(video_path, NULL);
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    sfSprite_setScale(data->sprite, snr_create_vector2f(2, 2));
    sfSprite_setPosition(data->sprite, snr_create_vector2f(
    win_size.x / 2 - 100, win_size.y / 2 - 57));
    data->start = engine->dt->since_start;
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(video);

    data->rect.left = ((int) ((engine->dt->since_start - data->start) * 25)
    % 100) * 100;
    sfSprite_setTextureRect(data->sprite, data->rect);
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(video);

    sfRenderWindow_drawSprite(engine->win, data->sprite, sfFalse);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(video);

    sfSprite_destroy(data->sprite);
    sfTexture_destroy(data->texture);
}

entity_t *create_entity_video(void)
{
    entity_t *ent = snr_entity_create();

    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
