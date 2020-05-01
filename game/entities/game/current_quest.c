/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** current_quest
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "rect_helper.h"
#include "scene.h"
#include "vector_helper.h"
#include "quests.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(current_quest);

    data->texture_panel =
    sfTexture_createFromFile("game/assets/ui/panel_beige.png", NULL);
    data->sprite_panel = sfSprite_create();
    sfSprite_setTexture(data->sprite_panel, data->texture_panel, sfFalse);
    sfSprite_setPosition(data->sprite_panel, snr_create_vector2f(10, 10));
    data->fnt = sfFont_createFromFile("engine/assets/fonts/Roboto-Regular.ttf");
    data->texts = malloc(sizeof(sfText *) * 100);
    for (int i = 0; i < 100; i++) {
        data->texts[i] = sfText_create();
        sfText_setFont(data->texts[i], data->fnt);
        sfText_setColor(data->texts[i], sfColor_fromRGB(30, 30, 30));
        sfText_setCharacterSize(data->texts[i], 16);
        sfText_setPosition(data->texts[i],
        snr_create_vector2f(20, 20 + i * 25));
    }
    data->shown = 1;
    data->loaded_quest = -1;
    data->last_pressed = 0;
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(current_quest);
    entity_player_data_t *p_data =
    snr_scene_get_entity(engine->sm->scene, "Player")->data;

    if (data->last_pressed && !sfKeyboard_isKeyPressed(sfKeyJ))
        data->shown = !data->shown;
    data->last_pressed = sfKeyboard_isKeyPressed(sfKeyJ);
    if (p_data->selected_quest == -1 || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        data->shown = 0;
        return;
    }
    if (p_data->selected_quest != data->loaded_quest) {
        data->loaded_quest = p_data->selected_quest;
        data->dialogs = get_quest_description(engine, data->loaded_quest);
    }
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(current_quest);

    if (!data->shown)
        return;
    sfRenderWindow_drawSprite(engine->win, data->sprite_panel, NULL);
    for (int i = 0; i < 100 && data->dialogs[i] != NULL; i++) {
        sfText_setString(data->texts[i], data->dialogs[i]);
        sfRenderWindow_drawText(engine->win, data->texts[i], NULL);
    }
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(current_quest);

    sfTexture_destroy(data->texture_panel);
    sfSprite_destroy(data->sprite_panel);
    sfFont_destroy(data->fnt);
    for (int i = 0; i < 100; i++)
        sfText_destroy(data->texts[i]);
    free(data->texts);
}

entity_t *create_current_quest(void)
{
    entity_t *ent = snr_entity_create();

    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    ent->depth = 20000;
    return (ent);
}
