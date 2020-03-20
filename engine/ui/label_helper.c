/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** label_helper
*/

#include "label_helper.h"
#include "rect_helper.h"
#include <stdlib.h>

entity_label_props_t *snr_ui_label_props(void)
{
    entity_label_props_t *props = malloc(sizeof(entity_label_props_t));

    props->string = "";
    props->rect = snr_create_floatrect(0, 0, 0, 0);
    props->size = 14;
    props->v_align = TOP;
    props->h_align = LEFT;
    props->color = sfWhite;
    return (props);
}
