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
#include "save.h"
#include "scene_manager.h"
#include "scenes.h"
#include "string_utils.h"
#include "string_convert.h"
#include <stdlib.h>

static void quit(engine_t *engine)
{
    save(engine);
    snr_scene_manager_load(engine, create_scene_main_menu(engine));
}

void open_main_menu(engine_t *engine, int bypass_key)
{
    menu_entry_t **entries;
    char *texts[] = {"MENU:", "Inventaire", "Stats du joueur", "Sauvegarder",
    "Quitter"};
    void *callbacks[] = {NULL, open_inventory, open_stats, save, quit};

    if (sfKeyboard_isKeyPressed(sfKeyI) || bypass_key) {
        entries = malloc(sizeof(menu_entry_t) * 6);
        for (int i = 0; i < 5; i++) {
            entries[i] = malloc(sizeof(menu_entry_t));
            entries[i]->text = my_strdup(texts[i]);
            entries[i]->callback = callbacks[i];
        }
        entries[5] = NULL;
        open_menu(engine, entries);
    }
}
