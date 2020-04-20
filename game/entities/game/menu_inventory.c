/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_inventory
*/

#include "engine.h"
#include "entities.h"
#include "entities_data.h"
#include "menu.h"
#include "inventory.h"
#include "string_utils.h"
#include "string_convert.h"
#include <stdlib.h>

static void add_item(engine_t *eng, menu_entry_t **entries, int *i, item_e item)
{
    menu_entry_t *entry;
    int *item_count = get_inventory_item(eng, item);

    if (*item_count == 0 || get_inventory_item_type(item) != OBJECT)
        return;
    entry = malloc(sizeof(menu_entry_t));
    entry->text = my_strcat(*item_count == 0 ? "0 " :
    my_strcat(itos(*item_count, 0), " "),
    get_inventory_item_name(item));
    entry->callback = get_inventory_item_use(item);
    entries[*i] = entry;
    (*i)++;
}

void open_inventory(engine_t *engine)
{
    menu_entry_t **entries = malloc(sizeof(menu_entry_t) * 100);
    int i = 0;

    entries[i++] = malloc(sizeof(menu_entry_t));
    entries[0]->text = my_strdup("VOTRE INVENTAIRE:");
    entries[0]->callback = NULL;
    for (int item = 0; item < MAX; item++)
        add_item(engine, entries, &i, item);
    entries[i] = NULL;
    open_menu(engine, entries);
}
