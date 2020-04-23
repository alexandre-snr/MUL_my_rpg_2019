/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight_info
*/

#include "entities.h"
#include "entities_data.h"
#include "engine.h"
#include "entity.h"
#include "rect_helper.h"
#include "vector_helper.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(fight);

    data->turn = 1;
    self->data = data;
}

entity_t *create_fight_manager(void)
{
    entity_t *ent = snr_entity_create();

    ent->init = init;
    return (ent);
}
