/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rain
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "random.h"
#include "scene.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(rain);

    for (int i = 0; i < RAIN_DROPS; i++) {
        data->drops[i].x = snr_rand(0, 10000000.0);
        data->drops[i].y = snr_rand(0, 10000000.0);
    }
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(rain);
    entity_camera_data_t *c_data
    = snr_scene_get_entity(engine->sm->scene, "Camera")->data;

    for (int i = 0; i < RAIN_DROPS; i++) {
        data->drops[i].y += engine->dt->val * 220 - c_data->delta.y;
        data->drops[i].x += engine->dt->val * 25 - c_data->delta.x;
    }
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(rain);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfImage *img =
    sfImage_createFromColor(win_size.x, win_size.y, sfTransparent);
    sfTexture *tex = NULL;
    sfSprite *spr = sfSprite_create();

    for (int i = 0; i < RAIN_DROPS; i++)
        for (int j = 0; j < 10; j++)
            sfImage_setPixel(img, (int) (data->drops[i].x + j / 4) % win_size.x,
            (int) (data->drops[i].y + j) % win_size.y,
            sfColor_fromRGBA(0, 0, 255, j * 255 / 20));
    tex = sfTexture_createFromImage(img, NULL);
    sfSprite_setTexture(spr, tex, sfTrue);
    sfRenderWindow_drawSprite(engine->win, spr, NULL);
    sfSprite_destroy(spr);
    sfTexture_destroy(tex);
    sfImage_destroy(img);
}

entity_t *create_rain(void)
{
    entity_t *ent = snr_entity_create();

    ent->depth = 10001;
    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    return (ent);
}
