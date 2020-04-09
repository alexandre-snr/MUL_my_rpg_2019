/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_update
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "menu.h"
#include "string_convert.h"
#include "string_utils.h"
#include <SFML/Window/Keyboard.h>
#include <stdlib.h>

static void debug(engine_t *engine)
{
    menu_entry_t **entries;

    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        entries = malloc(sizeof(menu_entry_t) * 21);
        for (int i = 0; i < 20; i++) {
            entries[i] = malloc(sizeof(menu_entry_t));
            entries[i]->text = itos(i + 1, 0);
        }
        entries[20] = NULL;
        open_menu(engine, entries);
    }
}

static void handle_selector(entity_menu_data_t *data)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && !data->last_key_down)
        data->entry_selected++;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && !data->last_key_up)
        data->entry_selected--;
    data->last_key_down = sfKeyboard_isKeyPressed(sfKeyDown);
    data->last_key_up = sfKeyboard_isKeyPressed(sfKeyUp);
    if (data->entry_selected < 0)
        data->entry_selected = 0;
    else if (data->entry_selected > data->entries_count - 1)
        data->entry_selected = data->entries_count - 1;
}

void menu_update(entity_t *self, engine_t *engine)
{
    DATA(menu);

    debug(engine);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        close_menu(engine);
    if (data->entries == NULL)
        return;
    handle_selector(data);
}
