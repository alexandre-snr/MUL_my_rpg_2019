/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_quests
*/

#include "engine.h"
#include "entities.h"
#include "entities_data.h"
#include "menu.h"
#include "inventory.h"
#include "scene.h"
#include "string_utils.h"
#include "string_convert.h"
#include <stdlib.h>

static void open_quest_details(engine_t *engine)
{
    entity_menu_data_t *m_data =
    snr_scene_get_entity(engine->sm->scene, "Menu")->data;

    printf("show %d\n", m_data->entry_selected);
}

static void add_item(engine_t *eng, menu_entry_t **entries, int *i, item_e item)
{
    menu_entry_t *entry;
    int *item_count = get_inventory_item(eng, item);

    if (*item_count == 0 || get_inventory_item_type(item) != QUEST)
        return;
    entry = malloc(sizeof(menu_entry_t));
    entry->text = get_inventory_item_name(item);
    entry->callback = open_quest_details;
    entries[*i] = entry;
    (*i)++;
}

void open_quests(engine_t *engine)
{
    menu_entry_t **entries = malloc(sizeof(menu_entry_t) * 100);
    int i = 0;

    entries[i++] = malloc(sizeof(menu_entry_t));
    entries[0]->text = my_strdup("VOS QUETES EN COURS:");
    entries[0]->callback = NULL;
    for (int item = 0; item < MAX; item++)
        add_item(engine, entries, &i, item);
    entries[i] = NULL;
    open_menu(engine, entries);
}
