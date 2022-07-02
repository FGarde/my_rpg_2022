/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** character_anim
*/

#include "global.h"

int is_it_idle(game_t *game)
{
    if (sfClock_getElapsedTime(game->character->clock).microseconds
    >= 300000) {
        game->character->direction %= 4;
        game->character->rect.left = 3;
        game->character->moving = false;
    }
    return 0;
}

int update_animation(game_t *game)
{
    is_it_idle(game);
    game->character->rect.top = 5 + game->character->direction * (28 + 4);
    sfSprite_setTextureRect(game->character->sprite, game->character->rect);
    return 0;
}

int define_direction(game_t *game, int direction, sfEvent event)
{
    game->character->direction = direction + 4;
    if (event.key.shift == sfTrue)
        game->character->direction += 4;
    game->character->rect.top = 5 + game->character->direction * (28 + 4);
    return 0;
}

int move_animation(game_t *game, int direction, sfEvent event)
{
    static bool move = true;

    if (!move && (direction + 4 == game->character->direction
    || direction + 8 == game->character->direction)) {
        move = true;
        return 0;
    }
    define_direction(game, direction, event);
    game->character->rect.left += 16;
    if (game->character->rect.left >= 95)
        game->character->rect.left = 3;
    move = false;
    sfClock_restart(game->character->clock);
    return 0;
}
