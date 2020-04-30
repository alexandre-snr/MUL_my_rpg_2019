/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** inco_del
*/

#include "engine.h"
#include "button.h"
#include "entities.h"
#include "button.h"
#include "label.h"
#include "scenes.h"
#include "label_helper.h"

static void create_button(scene_t *scn, void (*callback)(engine_t *),
sfFloatRect *rect)
{
    entity_button_props_t *props = malloc(sizeof(entity_button_props_t));
    entity_label_props_t *label_props = snr_ui_label_props();

    props->rect = *rect;
    props->callback = callback;
    rect->top -= rect->height * 0.1f;
    snr_scene_add_entity(scn, NULL, snr_ui_button_create(props), "Button");
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(label_props), "Label");
}

void create_icon_del(scene_t *scn, engine_t *engine)
{
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    void *callback[] = {on_del1_click, on_del2_click, on_del3_click};
    float buttons_height = win_size.y - 270;
    int buttons_count = 4;
    float button_height = (buttons_height / buttons_count) - 20;
    sfFloatRect icon_rect = {win_size.x / 2 + 400, 300, 50, 50};
    sfFloatRect button_rect = {win_size.x / 2 + 380, 320, button_height,
    button_height};

    for (int i = 0; i < 3; i++) {
        snr_scene_add_entity(scn, NULL, create_icon("game/assets/ui/cross.png",
        &icon_rect), "Icon Del");
        create_button(scn, callback[i], &button_rect);
        button_rect.top += 100;
        icon_rect.top += 100;
    }
}