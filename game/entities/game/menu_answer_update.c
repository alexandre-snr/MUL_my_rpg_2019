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
#include "npc.h"
#include <SFML/Window/Keyboard.h>
#include <stdlib.h>

static void move_selector(entity_menu_data_t *data, engine_t *engine)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && !data->last_key_down)
        data->entry_selected++;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && !data->last_key_up)
        data->entry_selected--;
}

static void handle_selector(entity_menu_data_t *data, engine_t *engine)
{
    int old_selected = data->entry_selected;

    move_selector(data, engine);
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && !data->last_key_enter
    && data->entry_selected > 0
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
    if (data->entries[1] == NULL)
        data->entry_selected = 0;
}

void menu_answer_update(entity_t *self, engine_t *engine)
{
    DATA(menu);

    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        close_menu_answer(engine);
    if (data->entries == NULL)
        return;
    handle_selector(data, engine);
}

void open_menu_ans(engine_t *engine)
{
    menu_entry_t **entries;
    char *texts[] =
    {"Reponse", "1. Oui", "1. Non"};
    void *callbacks[] = {NULL, on_yes, on_no};

        entries = malloc(sizeof(menu_entry_t) * 4);
        for (int i = 0; i < 3; i++) {
            entries[i] = malloc(sizeof(menu_entry_t));
            entries[i]->text = my_strdup(texts[i]);
            entries[i]->callback = callbacks[i];
        }
        entries[3] = NULL;
        open_menu(engine, entries);
}