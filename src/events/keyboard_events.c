/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** keyboard_events
*/

#include "global.h"

int movement_event(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyUp) {
        move_animation(game, 0, event);
        move_view(0, -1, game, &event);
    }
    if (event.key.code == sfKeyDown) {
        move_animation(game, 1, event);
        move_view(0, 1, game, &event);
    }
    if (event.key.code == sfKeyLeft) {
        move_animation(game, 2, event);
        move_view(-1, 0, game, &event);
    }
    if (event.key.code == sfKeyRight) {
        move_animation(game, 3, event);
        move_view(1, 0, game, &event);
    }
    return 0;
}

int pause_event(game_t *game, sfEvent event)
{
    if (game->paused) {
        if (event.key.code == sfKeyEscape) {
            if (game->music->music != NULL)
            sfMusic_play(game->music->music);
            game->paused = false;
        }
        else
            return 1;
    } else {
        if (event.key.code == sfKeyEscape) {
            if (game->music->music != NULL)
                sfMusic_pause(game->music->music);
            game->paused = true;
            return 1;
        }
    }
    return 0;
}

int key_pressed(game_t *game, sfEvent event)
{
    if (pause_event(game, event) == 1)
        return 0;
    if (event.key.code == sfKeyNum1)
        game->raining = !game->raining;
    if (event.key.code == sfKeyNum2)
        game->character->vulnerable = !(game->character->vulnerable);
    if (sfClock_getElapsedTime(game->clock).microseconds > 20000) {
        movement_event(game, event);
        if (event.key.code == sfKeyNumpad5)
            reset_zoom(game);
        if (event.key.code == sfKeyNumpad2)
            zoom_view(0.05, game);
        if (event.key.code == sfKeyNumpad8)
            zoom_view(-0.05, game);
        sfClock_restart(game->clock);
    }
    return (0);
}
