/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_deal
*/

#include "shop.h"
#include "engine.h"
#include "entities.h"
#include "string_utils.h"
#include "entities_data.h"

void open_menu_deal(engine_t *engine)
{
    menu_entry_t **entries;
    char *texts[] =
    {"MAGASIN", "Potions de vie   10$ ", "potions de mana    10$"};
    void *callbacks[] = {NULL, buy_health_potions, buy_mana_potions};

        entries = malloc(sizeof(menu_entry_t) * 4);
        for (int i = 0; i < 3; i++) {
            entries[i] = malloc(sizeof(menu_entry_t));
            entries[i]->text = my_strdup(texts[i]);
            entries[i]->callback = callbacks[i];
        }
        entries[3] = NULL;
        open_menu(engine, entries);
}