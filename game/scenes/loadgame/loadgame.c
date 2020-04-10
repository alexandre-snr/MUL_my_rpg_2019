/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loadgame
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

static char **create_labels(void)
{
    char **labels = malloc(sizeof(char *) * 5);
    ini_t *ini[] = {snr_ini_load("game/assets/configs/save/slot1.ini"),
    snr_ini_load("game/assets/configs/save/slot2.ini"), 
    snr_ini_load("game/assets/configs/save/slot3.ini")};

    labels[4] = NULL;
    for (int i = 0; i < 3; i++) {
        if (stoi(*snr_ini_get(ini[i], "status", "stat")))
            labels[i] = my_strcat("slot ", itos(i + 1, 0));
        else
            labels[i] = my_strdup("empty");
    }
    labels[3] = "Main Menu";
    return (labels);
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

static void create_title(scene_t *scn, engine_t *engine)
{
    entity_label_props_t *props = snr_ui_label_props();
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect = {win_size.x / 2 + 110, 50, 200, 100};

    props->color = sfWhite;
    props->string = "Choose your game";
    props->rect = rect;
    props->size = 80;
    props->h_align = RIGHT;
    props->v_align = CENTER;
    snr_scene_add_entity(scn, NULL, snr_ui_label_create(props), "Label My");
}

scene_t *create_scene_loadgame(engine_t *engine)
{
    scene_t *scn = snr_scene_create("Loadgame");
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    float buttons_height = win_size.y - 270;
    int buttons_count = 4;
    float button_height = (buttons_height / buttons_count) - 20;
    sfFloatRect button_rect = {win_size.x / 2 - 200, 0, 400, button_height};
    char **labels = create_labels();
    void (*callback[])(engine_t *) = {on_slot1_click, on_slot2_click,
    on_slot3_click, on_main_menu_click};

    create_title(scn, engine);
    for (int i = 0; i < buttons_count; i++) {
        button_rect.top = (buttons_height / buttons_count) * i + 230;
        create_button(scn, labels[i], callback[i], &button_rect);
    }
    return (scn);
}