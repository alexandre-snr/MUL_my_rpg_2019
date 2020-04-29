/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** button
*/

#include "button.h"
#include "entity.h"
#include "engine.h"
#include "vector_helper.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(button);
    PR(button);
    char const *normal_path = "engine/assets/ui/button_normal.png";
    char const *hover_path = "engine/assets/ui/button_hover.png";
    char const *pressed_path = "engine/assets/ui/button_pressed.png";

    data->rect = props->rect;
    data->callback = props->callback;
    data->last_pressed = 0;
    data->sprite = sfSprite_create();
    data->tex_normal = sfTexture_createFromFile(normal_path, NULL);
    data->tex_hover = sfTexture_createFromFile(hover_path, NULL);
    data->tex_pressed = sfTexture_createFromFile(pressed_path, NULL);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    DATA(button);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->win);
    int is_hover = sfFloatRect_contains(&data->rect, mouse_pos.x, mouse_pos.y);
    int pressed = sfMouse_isButtonPressed(0);
    sfTexture *tex = data->tex_normal;
    sfVector2u tex_size;

    if (is_hover && pressed)
        tex = data->tex_pressed;
    else if (is_hover && !pressed)
        tex = data->tex_hover;
    tex_size = sfTexture_getSize(tex);
    sfSprite_setTexture(data->sprite, tex, sfTrue);
    sfSprite_setScale(data->sprite, snr_create_vector2f(
    data->rect.width / tex_size.x, data->rect.height / tex_size.y));
    sfSprite_setPosition(data->sprite, snr_create_vector2f(
    data->rect.left, data->rect.top));
    if (data->last_pressed && !pressed && is_hover)
        data->callback(engine);
    data->last_pressed = pressed;
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(button);

    sfRenderWindow_drawSprite(engine->win, data->sprite, NULL);
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(button);

    sfSprite_destroy(data->sprite);
}

entity_t *snr_ui_button_create(entity_button_props_t *props)
{
    entity_t *ent = snr_entity_create();

    ent->props = props;
    ent->depth = 1000;
    ent->init = init;
    ent->depth = 10010;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
