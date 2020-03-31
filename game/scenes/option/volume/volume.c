/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** option_volume
*/

#include "button.h"
#include "label.h"
#include "label_helper.h"
#include "scene.h"
#include "scenes.h"
#include "entities.h"
#include "ini.h"
#include "string_utils.h"
#include "rect_helper.h"
#include <SFML/Graphics/Color.h>
#include <stdlib.h>

static entity_t *create_title(int size, int x, int y, char *title)
{
    entity_label_props_t *props = snr_ui_label_props();
    sfFloatRect rect = {x / 2 - 100, y, 200, 100};

    props->color = sfWhite;
    props->string = title;
    props->rect = rect;
    props->size = size;
    props->h_align = CENTER;
    props->v_align = CENTER;
    return (snr_ui_label_create(props));
}

static void create_effects(scene_t *scn, sfVector2u win_size)
{
    ini_t *ini = snr_ini_load("game/assets/configs/volume.ini");
    entity_button_props_t *fx_min_btn = malloc(sizeof(entity_button_props_t));
    entity_button_props_t *fx_max_btn = malloc(sizeof(entity_button_props_t));
    sfFloatRect fx_min_ico = {win_size.x / 2 - 130, 248, 20, 20};
    sfFloatRect fx_max_ico = {win_size.x / 2 + 110, 248, 20, 20};

    fx_min_btn->rect = snr_create_floatrect(win_size.x / 2 - 140, 240, 40, 40);
    fx_min_btn->callback = down_volume;
    fx_max_btn->rect = snr_create_floatrect(win_size.x / 2 + 100, 240, 40, 40);
    fx_max_btn->callback = up_volume;
    snr_scene_add_entity(scn, NULL, create_title(40, win_size.x, 200,
    my_strdup(*(snr_ini_get(ini, "volume", "effects")))), "");
    snr_ini_free(ini);
    snr_scene_add_entity(scn, NULL, snr_ui_button_create(fx_min_btn), "");
    snr_scene_add_entity(scn, NULL, snr_ui_button_create(fx_max_btn), "");
    snr_scene_add_entity(scn, NULL,
    create_icon("game/assets/ui/minus.png", &fx_min_ico), "");
    snr_scene_add_entity(scn, NULL,
    create_icon("game/assets/ui/plus.png", &fx_max_ico), "");
}

static void create_music(scene_t *scn, sfVector2u win_size)
{
    ini_t *ini = snr_ini_load("game/assets/configs/volume.ini");
    entity_button_props_t *fx_min_btn = malloc(sizeof(entity_button_props_t));
    entity_button_props_t *fx_max_btn = malloc(sizeof(entity_button_props_t));
    sfFloatRect fx_min_ico = {win_size.x / 2 - 130, 448, 20, 20};
    sfFloatRect fx_max_ico = {win_size.x / 2 + 110, 448, 20, 20};

    fx_min_btn->rect = snr_create_floatrect(win_size.x / 2 - 140, 440, 40, 40);
    fx_min_btn->callback = down_music_volume;
    fx_max_btn->rect = snr_create_floatrect(win_size.x / 2 + 100, 440, 40, 40);
    fx_max_btn->callback = up_music_volume;
    snr_scene_add_entity(scn, NULL, create_title(40, win_size.x, 400,
    my_strdup(*(snr_ini_get(ini, "volume", "music")))), "");
    snr_ini_free(ini);
    snr_scene_add_entity(scn, NULL, snr_ui_button_create(fx_min_btn), "");
    snr_scene_add_entity(scn, NULL, snr_ui_button_create(fx_max_btn), "");
    snr_scene_add_entity(scn, NULL,
    create_icon("game/assets/ui/minus.png", &fx_min_ico), "");
    snr_scene_add_entity(scn, NULL,
    create_icon("game/assets/ui/plus.png", &fx_max_ico), "");
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

scene_t *create_scene_volume(engine_t *engine)
{
    scene_t *scn = snr_scene_create("Option Volume");
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    sfFloatRect rect = {(win_size.x - 175) / 2, win_size.y - 200, 175, 75};

    snr_scene_add_entity(scn, NULL,
    create_title(80, win_size.x, 50, "Volume"), "");
    snr_scene_add_entity(scn, NULL,
    create_title(40, win_size.x, 150, "Effects"), "");
    snr_scene_add_entity(scn, NULL,
    create_title(40, win_size.x, 350, "Music"), "");
    create_effects(scn, win_size);
    create_music(scn, win_size);
    create_button(scn, "Back", on_options_click, &rect);
    return (scn);
}