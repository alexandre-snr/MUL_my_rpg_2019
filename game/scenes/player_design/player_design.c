/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** chose_player
*/

#include "scenes.h"
#include "entities.h"
#include "engine.h"
#include "label.h"
#include "label_helper.h"
#include "button.h"
#include "rect_helper.h"
#include "stdlib.h"

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

static void create_icon_next(scene_t *scn, engine_t *engine)
{
    entity_button_props_t *props_next = malloc(sizeof(entity_button_props_t));
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect_next = {win_size.x / 2 + 300, win_size.y / 2, 70, 70};
    sfFloatRect rect_ic_next = {win_size.x / 2 + 300 + 5,
    win_size.y / 2, 64, 64};

    props_next->rect = rect_next;
    props_next->callback = on_next_click;
    snr_scene_add_entity(scn, engine, snr_ui_button_create(props_next),
    "But Next");
    snr_scene_add_entity(scn, engine,
    create_icon("game/assets/ui/next.png", &rect_ic_next), "Icon Next");
}

static void create_icon_previous(scene_t *scn, engine_t *engine)
{
    entity_button_props_t *props_previous =
    malloc(sizeof(entity_button_props_t));
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect_previous = {win_size.x / 2 - 365, win_size.y / 2, 70, 70};
    sfFloatRect rect_ic_previous = {win_size.x / 2 - 365 + 5,
    win_size.y / 2, 64, 64};

    props_previous->rect = rect_previous;
    props_previous->callback = on_previous_click;
    snr_scene_add_entity(scn, engine, snr_ui_button_create(props_previous),
    "But Previous");
    snr_scene_add_entity(scn, engine,
    create_icon("game/assets/ui/back.png", &rect_ic_previous), "Icon Previous");
}

static void create_title(scene_t *scn, engine_t *engine)
{
    entity_label_props_t *props = snr_ui_label_props();
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect = {win_size.x / 2 + 110, 25, 300, 100};

    props->color = sfWhite;
    props->string = "Choix du personnage";
    props->rect = rect;
    props->size = 80;
    props->h_align = RIGHT;
    props->v_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(props), "Label My");
}

scene_t *create_scene_playerdesign(engine_t *engine)
{
    scene_t *scn = snr_scene_create("Chara Design");
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect_start = snr_create_floatrect(win_size.x / 2 - 200,
    win_size.y / 2 + 200, 400, 100);

    snr_scene_add_entity(scn, NULL,
    create_menu_background("game/assets/sprites/maps/main-menu.png"),
    "Background");
    create_title(scn, engine);
    snr_scene_add_entity(scn, engine, create_preview(0), "Preview");
    create_button(scn, "Start", on_start_click, &rect_start);
    create_icon_next(scn, engine);
    create_icon_previous(scn, engine);
    return (scn);
}
