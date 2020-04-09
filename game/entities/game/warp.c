/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** warp
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "map_change.h"
#include "scene.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>

static void update(entity_t *self, engine_t *engine)
{
    PR(warp);
    entity_player_data_t *p_data =
    snr_scene_get_entity(engine->sm->scene, "Player")->data;
    sfFloatRect p_rect = sfSprite_getGlobalBounds(p_data->sprite);
    map_change_t *map_change;

    if (sfFloatRect_intersects(&(props->coll), &p_rect, NULL)) {
        map_change = malloc(sizeof(map_change_t));
        map_change->map = props->map;
        map_change->player_pos = props->player_pos;
        load_map(engine, map_change, props->slot_number);
    }
}

entity_t *create_warp(sfFloatRect *coll, maps_e map, sfVector2f *player_pos,
int slot_number)
{
    entity_t *ent = snr_entity_create();
    entity_warp_props_t *pr = malloc(sizeof(entity_warp_props_t));

    pr->coll = *coll;
    pr->map = map;
    pr->player_pos = *player_pos;
    pr->slot_number = slot_number;
    ent->props = pr;
    ent->update = update;
    return (ent);
}
