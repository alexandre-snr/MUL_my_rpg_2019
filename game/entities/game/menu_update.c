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

static void add_item(engine_t *eng, menu_entry_t **entries, int *i, item_e item)
{
    menu_entry_t *entry;
    int *item_count = get_inventory_item(eng, item);

    entry = malloc(sizeof(menu_entry_t));
    entry->text = my_strcat(*item_count == 0 ? "0 " :
    my_strcat(itos(*item_count, 0), " "),
    get_inventory_item_name(item));
    entry->callback = get_inventory_item_use(item);
    entries[*i] = entry;
    (*i)++;
}

static void open_inventory(engine_t *engine, int bypass_key)
{
    menu_entry_t **entries;
    int i = 0;

    if (sfKeyboard_isKeyPressed(sfKeyI) || bypass_key) {
        entries = malloc(sizeof(menu_entry_t) * 100);
        entries[i++] = malloc(sizeof(menu_entry_t));
        entries[0]->text = my_strdup("VOTRE INVENTAIRE:");
        entries[0]->callback = NULL;
        for (int item = 0; item < MAX; item++)
            add_item(engine, entries, &i, item);
        entries[i] = NULL;
        open_menu(engine, entries);
    }
}

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
        open_inventory(engine, 1);
        data->entry_selected = old_selected;
    }
    data->last_key_down = sfKeyboard_isKeyPressed(sfKeyDown);
    data->last_key_up = sfKeyboard_isKeyPressed(sfKeyUp);
    data->last_key_enter = sfKeyboard_isKeyPressed(sfKeyReturn);
    if (data->entry_selected < 0)
        data->entry_selected = 0;
    else if (data->entry_selected > data->entries_count - 1)
        data->entry_selected = data->entries_count - 1;
}

void menu_update(entity_t *self, engine_t *engine)
{
    DATA(menu);

    open_inventory(engine, 0);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        close_menu(engine);
    if (data->entries == NULL)
        return;
    handle_selector(data, engine);
}
