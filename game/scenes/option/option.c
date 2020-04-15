/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** option
*/

#include "scenes.h"
#include "entity.h"
#include "entities.h"
#include "button.h"
#include "label.h"
#include "label_helper.h"
#include <stdlib.h>

static void create_title(scene_t *scn, engine_t *engine)
{
    entity_label_props_t *props = snr_ui_label_props();
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect = {win_size.x / 2 - 100, 50, 200, 100};

    props->color = sfWhite;
    props->string = "Options";
    props->rect = rect;
    props->size = 80;
    props->h_align = CENTER;
    props->v_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(props),
    "Label Options");
}

static void create_button(scene_t *scn, char const *title,
void (*callbacks)(engine_t *), sfFloatRect *rect)
{
    entity_button_props_t *props = malloc(sizeof(entity_button_props_t));
    entity_label_props_t *label_props = snr_ui_label_props();

    props->rect = *rect;
    props->callback = callbacks;
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

scene_t *create_scene_option(engine_t *engine)
{
    scene_t *scn = snr_scene_create("Options");
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    int buttons_count = 3;
    float buttons_height = win_size.y - 400;
    float button_height = (buttons_height / buttons_count) - 20;
    sfFloatRect button_rect = {win_size.x / 2 - 200, 0, 400, button_height};
    char *labels[] = {"Resolution", "Volume", "Retour"};
    void (*callbacks[])(engine_t *) = {on_resolution_click, on_volume_click,
    on_main_menu_click};

    create_title(scn, engine);
    for (int i = 0; i < buttons_count; i++) {
        button_rect.top = (buttons_height / buttons_count) * i + 230;
        create_button(scn, labels[i], callbacks[i], &button_rect);
    }
    return (scn);
}
