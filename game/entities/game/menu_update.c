/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_update
*/

#include "entities.h"
#include "entities_data.h"
#include "entity.h"
#include "inventory.h"
#include "menu.h"
#include "string_convert.h"
#include "string_utils.h"
#include <SFML/Window/Keyboard.h>
#include <stdlib.h>


static void handle_selector(entity_menu_data_t *data, engine_t *engine)
{
    int old_selected = data->entry_selected;

    if (sfKeyboard_isKeyPressed(sfKeyDown) && !data->last_key_down)
        data->entry_selected++;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && !data->last_key_up)
        data->entry_selected--;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && !data->last_key_enter
    && data->entries[data->entry_selected]->callback != NULL) {
        data->entries[data->entry_selected]->callback(engine);
        data->entry_selected = old_selected;
    }
    data->last_key_down = sfKeyboard_isKeyPressed(sfKeyDown);
    data->last_key_up = sfKeyboard_isKeyPressed(sfKeyUp);
    data->last_key_enter = sfKeyboard_isKeyPressed(sfKeyReturn);
    if (data->entry_selected < 1)
        data->entry_selected = 1;
    else if (data->entry_selected > data->entries_count - 1)
        data->entry_selected = data->entries_count - 1;
}

void menu_update(entity_t *self, engine_t *engine)
{
    DATA(menu);

    open_main_menu(engine, 0);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        close_menu(engine);
    if (data->entries == NULL)
        return;
    handle_selector(data, engine);
}
