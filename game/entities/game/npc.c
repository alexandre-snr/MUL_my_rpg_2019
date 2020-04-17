/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** npc
*/

#include "npc.h"
#include "engine.h"
#include "entities.h"
#include "entities_data.h"
#include "string_utils.h"

static void init(entity_t *self, engine_t *engine)
{
    IDATA(npc);
    PR(npc);
    char *path[] = {"game/assets/sprites/npc/test.png", NULL};
    sfVector2f pos = {100, 200};

    data->sprite = sfSprite_create();
    data->rect.left = 100;
    data->rect.top = 220;
    data->rect.height = 20;
    data->rect.width = 20;
    data->create = 0;
    data->texture = sfTexture_createFromFile(path[props->npc_type], NULL);
    sfSprite_setPosition(data->sprite, pos);
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(npc);
    entity_player_data_t *data_player =
    snr_scene_get_entity(engine->sm->scene, "Player")->data;
    sfFloatRect rect_player =
    {data_player->pos.x, data_player->pos.y + 20, 20, 20};

    if (sfFloatRect_intersects(&rect_player, &data->rect, NULL) &&
    sfKeyboard_isKeyPressed(sfKeyE) && !data->create) {
        snr_scene_add_entity(engine->sm->scene, engine,
        create_menu_talk(default_talk), my_strdup("Talk"));
        data->create = 1;
    }
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(npc);

    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

entity_t *create_npc(npc_e npc_type, sfVector2f pos)
{
    IPR(npc);
    entity_t *ent = snr_entity_create();

    pr->npc_type = npc_type;
    pr->pos = &pos;
    ent->props = pr;
    ent->init = init;
    ent->draw = draw;
    ent->update = update;
    return (ent);
}