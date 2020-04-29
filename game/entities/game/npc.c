/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** npc
*/

#include "npc.h"
#include "shop.h"
#include "engine.h"
#include "entities.h"
#include "entities_data.h"
#include "string_utils.h"
#include "rect_helper.h"

static void init(entity_t *self, engine_t *engine)
{
    IDATA(npc);
    PR(npc);
    char *path[] = {"game/assets/sprites/npc/men.png",
    "game/assets/sprites/npc/women.png",
    "game/assets/sprites/npc/dealer.png",NULL};
    sfFloatRect coll;

    data->sprite = sfSprite_create();
    data->rect.left = props->pos.x;
    data->rect.top = props->pos.y + 20;
    data->rect.height = 20;
    data->rect.width = 20;
    coll = snr_create_floatrect(props->pos.x, props->pos.y, 20, 20);
    add_collider(engine, &coll);
    data->texture = sfTexture_createFromFile(path[props->npc_type], NULL);
    sfSprite_setPosition(data->sprite, props->pos);
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    data->handler = props->handler;
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(npc);
    PR(npc);
    entity_player_data_t *data_player =
    snr_scene_get_entity(engine->sm->scene, "Player")->data;
    sfFloatRect rect_player =
    {data_player->pos.x, data_player->pos.y + 20, 20, 20};

    if (sfFloatRect_intersects(&rect_player, &data->rect, NULL) &&
    sfKeyboard_isKeyPressed(sfKeyE) && props->npc_type == DEALER) {
        open_menu_deal(engine);
    } else if (sfFloatRect_intersects(&rect_player, &data->rect, NULL) &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        open_talk(engine, default_talk);
        open_menu_ans(engine);
    }
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(npc);

    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

entity_t *create_npc(npc_e npc_type, sfVector2f pos,
char **(*handler)(engine_t *))
{
    IPR(npc);
    entity_t *ent = snr_entity_create();

    pr->npc_type = npc_type;
    pr->pos = pos;
    ent->props = pr;
    ent->init = init;
    ent->draw = draw;
    ent->update = update;
    ent->depth = 5000 + pos.y;
    return (ent);
}
