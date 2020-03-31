/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** splashscreen
*/

#include "scene.h"
#include "scenes.h"
#include "entities.h"

scene_t *create_scene_splashscreen(void)
{
    scene_t *scn = snr_scene_create("Splashscreen");

    snr_scene_add_entity(scn, NULL, create_entity_video(), "Video");
    snr_scene_add_entity(scn, NULL, create_entity_sound(), "Sound");
    return (scn);
}
