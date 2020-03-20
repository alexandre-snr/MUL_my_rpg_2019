/*
** EPITECH PROJECT, 2019
** MUL_snr_engine_2019
** File description:
** engine
*/

#include "engine.h"
#include "random.h"
#include <stdlib.h>

engine_t *snr_engine_create(char const *title, sfVector2i size)
{
    engine_t *engine = malloc(sizeof(engine_t));
    sfVideoMode videoMode = {size.x, size.y, 32};

    if (engine == NULL)
        return (NULL);
    engine->win = sfRenderWindow_create(videoMode, title, sfClose, NULL);
    if (engine->win == NULL) {
        snr_engine_destroy(engine);
        return (NULL);
    }
    engine->sm = snr_scene_manager_create();
    if (engine->sm == NULL) {
        snr_engine_destroy(engine);
        return (NULL);
    }
    engine->dt = snr_dt_create();
    sfRenderWindow_setFramerateLimit(engine->win, 60);
    snr_rand_init();
    return (engine);
}

void snr_engine_run(engine_t *engine)
{
    if (engine == NULL)
        return;
    while (sfRenderWindow_isOpen(engine->win)) {
        snr_engine_update(engine);
        snr_engine_draw(engine);
    }
}

void snr_engine_destroy(engine_t *engine)
{
    if (!engine)
        return;
    if (engine->win)
        sfRenderWindow_destroy(engine->win);
    if (engine->sm)
        snr_scene_manager_destroy(engine);
    if (engine->dt)
        snr_dt_destroy(engine->dt);
    free(engine);
}

void snr_engine_update(engine_t *engine)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(engine->win, &e))
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(engine->win);
        else
            snr_scene_manager_pevent(engine, &e);
    snr_dt_update(engine->dt);
    snr_scene_manager_update(engine);
}

void snr_engine_draw(engine_t *engine)
{
    sfRenderWindow_clear(engine->win, sfBlack);
    snr_scene_manager_draw(engine);
    sfRenderWindow_display(engine->win);
}