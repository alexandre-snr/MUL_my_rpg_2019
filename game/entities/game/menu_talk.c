/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_talk
*/

#include "engine.h"
#include "save.h"
#include "entities.h"
#include "entities_data.h"
#include "string_utils.h"
#include "vector_helper.h"

static void init(entity_t *self, engine_t *engine)
{
    IDATA(menu_talk);
    PR(menu_talk);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfVector2f pos = {win_size.x / 2 - 300, win_size.y - 110};
    char **(*handler)(engine_t *) = props->handler;

    data->conv = handler(engine);
    data->total = my_arrlen(data->conv);
    data->text = malloc(sizeof(sfText *) * (data->total + 1));
    data->is_finish = 0;
    data->texture = sfTexture_createFromFile("game/assets/ui/panel_beige.png",
    NULL);
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    sfSprite_setScale(data->sprite, snr_create_vector2f(6, 1));
    sfSprite_setPosition(data->sprite, pos);
    self->data = data;
    init_talk(self, engine, data->total);
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(menu_talk);

    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
    for (int i = data->page; i < data->page + 3; i++) {
        if (i < data->total)
            sfRenderWindow_drawText(engine->win, data->text[i], NULL);
    }
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(menu_talk);
    entity_npc_data_t *npc_data =
    snr_scene_get_entity(engine->sm->scene, "Npc")->data;

    data->dt_time += engine->dt->val;
    if (data->page >= data->total / 3)
        data->is_finish = 1;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && data->is_finish) {
        snr_scene_remove_entity(engine->sm->scene, self->id);
        npc_data->create = 0;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && data->dt_time >= 0.5f &&
    !data->is_finish) {
        data->page += 3;
        data->dt_time = 0;
    }
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(menu_talk);

    for (int i = 0; data->text[i] != NULL; i++) {
        sfText_destroy(data->text[i]);
        free(data->conv[i]);
    }
    sfSprite_destroy(data->sprite);
    sfTexture_destroy(data->texture);
    free(data->conv);
    sfFont_destroy(data->font);
}

entity_t *create_menu_talk(char **(*handler)(engine_t *), char *name)
{
    entity_t *ent = snr_entity_create();
    IPR(menu_talk);

    pr->handler = handler;
    ent->props = pr;
    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
