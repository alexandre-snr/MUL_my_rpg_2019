/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

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

static void load_tex_sprites(entity_menu_data_t *data, engine_t *engine)
{
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);

    data->texture_panel =
    sfTexture_createFromFile("game/assets/ui/panel_beige.png", NULL);
    data->sprite_panel = sfSprite_create();
    sfSprite_setTexture(data->sprite_panel, data->texture_panel, sfTrue);
    sfSprite_setPosition(data->sprite_panel,
    snr_create_vector2f(win_size.x - 410, 10));
    data->texture_selected =
    sfTexture_createFromFile("game/assets/ui/panel_beigeLight.png", NULL);
    data->sprite_selected = sfSprite_create();
    sfSprite_setTexture(data->sprite_selected, data->texture_selected, sfFalse);
}

static void init(entity_t *self, engine_t *engine)
{
    IDATA(menu);

    data->entries = NULL;
    data->font =
    sfFont_createFromFile("engine/assets/fonts/Roboto-Regular.ttf");
    data->text = sfText_create();
    sfText_setFont(data->text, data->font);
    sfText_setColor(data->text, sfColor_fromRGB(30, 30, 30));
    sfText_setCharacterSize(data->text, 16);
    load_tex_sprites(data, engine);
    self->data = data;
}

static void draw(entity_t *self, engine_t *engine)
{
    DATA(menu);
    sfVector2u win_size = sfRenderWindow_getSize(engine->win);
    int scroll = 0;

    if (data->entries == NULL)
        return;
    if (data->entry_selected > 7)
        scroll = data->entry_selected - 7;
    sfRenderWindow_drawSprite(engine->win, data->sprite_panel, NULL);
    sfSprite_setPosition(data->sprite_selected,
    snr_create_vector2f(win_size.x - 385,
    40 + 50 * (data->entry_selected - scroll)));
    sfRenderWindow_drawSprite(engine->win, data->sprite_selected, NULL);
    for (int i = scroll; data->entries[i] && i < 9 + scroll; i++) {
        sfText_setString(data->text, data->entries[i]->text);
        sfText_setPosition(data->text,
        snr_create_vector2f(win_size.x - 370, 45 + 50 * (i - scroll)));
        sfRenderWindow_drawText(engine->win, data->text, NULL);
    }
}

static void destroy(entity_t *self, engine_t *engine)
{
    DATA(menu);

    close_menu(engine);
    sfTexture_destroy(data->texture_panel);
    sfSprite_destroy(data->sprite_panel);
    sfText_destroy(data->text);
    sfFont_destroy(data->font);
}

entity_t *create_menu(void)
{
    entity_t *ent = snr_entity_create();

    ent->depth = 10002;
    ent->init = init;
    ent->update = menu_update;
    ent->draw = draw;
    ent->destroy = destroy;
    return (ent);
}
