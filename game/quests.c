/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quests
*/

#include "ini.h"
#include "inventory.h"
#include "string_utils.h"
#include "string_convert.h"
#include <stdlib.h>

static char *get_part(engine_t *engine, item_e quest)
{
    int part = *get_inventory_item(engine, quest);

    return (part != 0 ? itos(part, 0) : my_strdup("0"));
}

char **get_quest_description(engine_t *engine, item_e quest)
{
    char *part = get_part(engine, quest);
    char **result = malloc(sizeof(char *) * 6);
    char *path = my_strcat(my_strcat("game/assets/configs/quests/",
    quest != 0 ? itos(quest, 0) : "0"), ".ini");
    ini_t *ini = snr_ini_load(path);
    int i = 0;

    for (; snr_ini_get(ini, part, i != 0 ? itos(i, 0) : "0"); i++)
        result[i] =
        my_strdup(*snr_ini_get(ini, part, i != 0 ? itos(i, 0) : "0"));
    result[i] = NULL;
    snr_ini_free(ini);
    free(path);
    return (result);
}

int is_quest_over(engine_t *engine, item_e quest)
{
    ini_t *ini = snr_ini_load("game/assets/configs/items.ini");
    char *name = quest != 0 ? itos(quest, 0) : my_strdup("0");
    int result = stoi(*snr_ini_get(ini, name, "parts"));

    snr_ini_free(ini);
    free(name);
    return (result < *get_inventory_item(engine, quest));

}
