/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "string_utils.h"
#include "vector_helper.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Keyboard.h>
#include <stdlib.h>

static void init(entity_t *self, engine_t *engine)
{
    IDATA(menu);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);

    data->texture_panel =
    sfTexture_createFromFile("game/assets/ui/panel_beige.png", NULL);
    data->sprite_panel = sfSprite_create();
    sfSprite_setTexture(data->sprite_panel, data->texture_panel, sfTrue);
    sfSprite_setScale(data->sprite_panel, snr_create_vector2f(4, 5));
    sfSprite_setPosition(data->sprite_panel,
    snr_create_vector2f(win_size.x - 410, 10));
    data->entries = NULL;
    data->font =
    sfFont_createFromFile("engine/assets/fonts/Roboto-Regular.ttf");
    data->text = sfText_create();
    sfText_setFont(data->text, data->font);
    sfText_setColor(data->text, sfColor_fromRGB(30, 30, 30));
    sfText_setCharacterSize(data->text, 16);
    self->data = data;
}

static void update(entity_t *self, engine_t *engine)
{
    menu_entry_t **entries;

    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        entries = malloc(sizeof(menu_entry_t) * 10);
        for (int i = 0; i < 9; i++) {
            entries[i] = malloc(sizeof(menu_entry_t));
            entries[i]->text = my_strdup("A random entry");
        }
        entries[10] = NULL;
        open_menu(engine, entries);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        close_menu(engine);
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(menu);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);

    if (data->entries == NULL)
        return;
    sfRenderWindow_drawSprite(engine->win, data->sprite_panel, NULL);
    for (int i = 0; data->entries[i] && i < 9; i++) {
        sfText_setString(data->text, data->entries[i]->text);
        sfText_setPosition(data->text,
        snr_create_vector2f(win_size.x - 370, 45 + 50 * i));
        sfRenderWindow_drawText(engine->win, data->text, NULL);
    }
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(menu);

    sfTexture_destroy(data->texture_panel);
    sfSprite_destroy(data->sprite_panel);
    sfText_destroy(data->text);
    sfFont_destroy(data->font);
    close_menu(engine);
}

entity_t *create_menu(void)
{
    entity_t *ent = snr_entity_create();

    ent->init = init;
    ent->update = update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
