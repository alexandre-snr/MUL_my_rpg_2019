/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_curret_slot
*/

#include "ini.h"
#include "string_utils.h"

char *get_current_slot(void)
{
    ini_t *ini = snr_ini_load("game/assets/configs/save/current_slot.ini");
    char *path = my_strdup(*snr_ini_get(ini, "current", "slot"));

    snr_ini_free(ini);
    return (path);
}