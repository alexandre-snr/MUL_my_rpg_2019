/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** main_menu
*/

#include "button.h"
#include "label.h"
#include "label_helper.h"
#include "scene.h"
#include "scenes.h"
#include "entities.h"
#include <SFML/Graphics/Color.h>
#include <stdlib.h>

static void create_title_2(scene_t *scn, engine_t *engine)
{
    entity_label_props_t *props = snr_ui_label_props();
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect = {win_size.x / 2 - 25, 50, 200, 100};

    props->color = sfColor_fromRGB(157, 53, 235);
    props->string = "RPG";
    props->rect = rect;
    props->size = 100;
    props->h_align = LEFT;
    props->v_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(props), "Label RPG");
}

static void create_title(scene_t *scn, engine_t *engine)
{
    entity_label_props_t *props = snr_ui_label_props();
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect = {win_size.x / 2 - 250, 50, 200, 100};

    props->color = sfWhite;
    props->string = "MY";
    props->rect = rect;
    props->size = 80;
    props->h_align = RIGHT;
    props->v_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(props), "Label My");
    create_title_2(scn, engine);
}

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

scene_t *create_scene_main_menu(engine_t *engine)
{
    scene_t *scn = snr_scene_create("Main Menu");
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    float buttons_height = win_size.y - 270;
    int buttons_count = 4;
    float button_height = (buttons_height / buttons_count) - 20;
    sfFloatRect button_rect = {win_size.x / 2 - 200, 0, 400, button_height};
    char *labels[] = {"Play", "How to play", "Options", "Quit"};
    void (*callbacks[])(engine_t *) = {on_play_click, on_how_to_click,
    on_options_click, on_quit_click};

    create_title(scn, engine);
    for (int i = 0; i < buttons_count; i++) {
        button_rect.top = (buttons_height / buttons_count) * i + 230;
        create_button(scn, labels[i], callbacks[i], &button_rect);
    }
    return (scn);
}