/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** autosave
*/

#include <stdlib.h>
#include "engine.h"
#include "entities.h"
#include "entities_data.h"
#include "save.h"

static void init(entity_t *self, engine_t *engine)
{
    IDATA(autosave);

    data->dt_save = 0;
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(autosave);

    data->dt_save += engine->dt->val;
    if (data->dt_save >= 120.0f) {
        save(engine);
        data->dt_save = 0.0f;
    }
}

entity_t *create_autosave(void)
{
    entity_t *ent = snr_entity_create();

    ent->update = update;
    ent->init = init;
    return (ent);
}