/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_entries
*/

#include "entities.h"
#include "entities_data.h"
#include "scene.h"
#include "menu.h"
#include <stdlib.h>

void open_menu(engine_t *engine, menu_entry_t **entries)
{
    entity_menu_data_t *m_data =
    snr_scene_get_entity(engine->sm->scene, "Menu")->data;

    close_menu(engine);
    m_data->entries = entries;
    m_data->entries_count = 0;
    for (m_data->entries_count = 0;
    m_data->entries[m_data->entries_count]; m_data->entries_count++);
    m_data->entry_selected = 0;
}

void close_menu(engine_t *engine)
{
    entity_menu_data_t *m_data =
    snr_scene_get_entity(engine->sm->scene, "Menu")->data;

    if (m_data->entries == NULL)
        return;
    for (int i = 0; m_data->entries[i] != NULL; i++) {
        free(m_data->entries[i]->text);
        free(m_data->entries[i]);
    }
    free(m_data->entries);
    m_data->entries = NULL;
}
