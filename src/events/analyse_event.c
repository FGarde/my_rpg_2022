/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** analyse_event
*/

#include "global.h"

int analyse_event(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        if (game->music->music != NULL)
            sfMusic_destroy(game->music->music);
        sfRenderWindow_close(game->Window->window);
    }
    if (event.type == sfEvtKeyPressed) {
        key_pressed(game, event);
    }
    return 0;
}

int event_loop(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->Window->window, &event)) {
        analyse_event(game, event);
    }
    return 0;
}
