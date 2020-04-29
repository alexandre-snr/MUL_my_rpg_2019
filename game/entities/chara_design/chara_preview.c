/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** chara_preview
*/

#include <stdlib.h>
#include "entity.h"
#include "entities_data.h"
#include "engine.h"
#include "vector_helper.h"

static void create_path(entity_preview_data_t *data)
{
    data->path_game = malloc(sizeof(char *) * 5);
    data->path = malloc(sizeof(char *) * 5);
    data->path[0] = "game/assets/sprites/players_preview/chara1.png";
    data->path[1] = "game/assets/sprites/players_preview/chara2.png";
    data->path[2] = "game/assets/sprites/players_preview/chara3.png";
    data->path[3] = "game/assets/sprites/players_preview/chara4.png";
    data->path[4] = NULL;
    data->path_game[0] = "game/assets/sprites/players/chara1.png";
    data->path_game[1] = "game/assets/sprites/players/chara2.png";
    data->path_game[2] = "game/assets/sprites/players/chara3.png";
    data->path_game[3] = "game/assets/sprites/players/chara4.png";
    data->path_game[4] = NULL;
}

static void init(entity_t *self, engine_t *engine)
{
    IDATA(preview);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfVector2f scale = {5, 5};

    create_path(data);
    data->pos = snr_create_vector2f((win_size.x / 2) - (19.0f / 2.0f) * 5,
    (win_size.y / 2) - (31.0f / 2.0f)* 5);
    data->sprite = malloc(sizeof(sfSprite *) * 4);
    data->tex = malloc(sizeof(sfTexture *) * 4);
    for (int i = 0; data->path[i] != NULL; i++) {
        data->tex[i] = sfTexture_createFromFile(data->path[i], NULL);
        data->sprite[i] = sfSprite_create();
        sfSprite_setTexture(data->sprite[i], data->tex[i], sfTrue);
        sfSprite_setPosition(data->sprite[i], data->pos);
        sfSprite_setScale(data->sprite[i], scale);
    }
    self->data = data;
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(preview);
    PR(preview);

    sfRenderWindow_drawSprite(engine->win, data->sprite[props->number % 4],
    NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(preview);

    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(data->tex[i]);
        sfSprite_destroy(data->sprite[i]);
    }
    free(data->path);
    free(data->path_game);
}

entity_t *create_preview(int number)
{
    entity_t *ent = snr_entity_create();
    entity_preview_props_t *pr = malloc(sizeof(entity_preview_props_t));

    pr->number = number;
    ent->props = pr;
    ent->depth = 500;
    ent->draw = draw;
    ent->init = init;
    ent->destroy = destroy;
    return (ent);
}
