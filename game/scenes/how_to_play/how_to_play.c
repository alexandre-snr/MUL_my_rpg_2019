/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** how_to_play
*/

#include <stdlib.h>
#include "button.h"
#include "label.h"
#include "label_helper.h"
#include "engine.h"
#include "scenes.h"
#include "ini.h"
#include "string_convert.h"
#include "string_utils.h"
#include "entities.h"

static void create_button(scene_t *scn, char const *title,
void (*callback)(engine_t *), sfFloatRect *rect)
{
    entity_button_props_t *props = malloc(sizeof(entity_button_props_t));
    entity_label_props_t *label_props = snr_ui_label_props();

    props->rect = *rect;
    props->callback = callback;
    label_props->color = sfBlack;
    label_props->size = 26;
    rect->top -= rect->height * 0.1f;
    label_props->rect = *rect;
    label_props->string = title;
    label_props->v_align = CENTER;
    label_props->h_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_button_create(props), "Button");
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(label_props), "Label");
}

scene_t *create_scene_howtoplay(engine_t *engine)
{
    char const *bg_path = "game/assets/sprites/howtoplay.png";
    scene_t *scn = snr_scene_create("How to Play");
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect = {(win_size.x - 230) / 2, win_size.y - 200, 250, 100};

    snr_scene_add_entity(scn, NULL, create_how_background(bg_path, 0), "Back");
    snr_scene_add_entity(scn, NULL, create_reset_view(), "Reset View");
    create_button(scn, "Menu principal", on_main_menu_click, &rect);
    return (scn);
}