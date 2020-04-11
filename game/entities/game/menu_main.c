/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_main
*/

#include "engine.h"
#include "menu.h"
#include "entities.h"
#include "entities_data.h"
#include "inventory.h"
#include "string_utils.h"
#include "string_convert.h"
#include <stdlib.h>

void open_main_menu(engine_t *engine, int bypass_key)
{
    menu_entry_t **entries;
    char *texts[] = {"MENU:", "Inventaire", "Stats du joueur"};
    void *callbacks[] = {NULL, open_inventory, open_stats};

    if (sfKeyboard_isKeyPressed(sfKeyI) || bypass_key) {
        entries = malloc(sizeof(menu_entry_t) * 4);
        for (int i = 0; i < 3; i++) {
            entries[i] = malloc(sizeof(menu_entry_t));
            entries[i]->text = my_strdup(texts[i]);
            entries[i]->callback = callbacks[i];
        }
        entries[3] = NULL;
        open_menu(engine, entries);
    }
}
