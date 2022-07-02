/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** edit_view
*/

#include "global.h"

bool is_colliding(int x, int y, game_t *game)
{
    sfColor on = sfImage_getPixel(game->maps->map_collision, x, y + 5);

    if (on.r == sfWhite.r && on.g == sfWhite.g && on.b == sfWhite.b)
        return false;
    return true;
}

int move_view(int x, int y, game_t *game, sfEvent *event)
{
    if (event != NULL) {
        if (event->key.shift == sfTrue) {
            x *= 2;
            y *= 2;
        }
    }
    if (is_colliding(game->view_pos.x + x, game->view_pos.y + y,game))
        return (0);
    game->view_pos.y += y;
    game->view_pos.x += x;
    game->character->hitbox.left = game->view_pos.x - 6;
    game->character->hitbox.top = game->view_pos.y;
    sfView_setCenter(game->view, game->view_pos);
    sfSprite_setPosition(game->character->sprite, (sfVector2f)\
    {game->view_pos.x - 6, game->view_pos.y - 10});
    game->character->moving = true;
    return (0);
}

int zoom_view(float zoom, game_t *game)
{
    if (zoom >= 0)
        game->zoom += 1;
    else
        game->zoom -= 1;
    if (game->zoom > 10) {
        game->zoom = 10;
        return (0);
    }
    if (game->zoom < 0) {
        game->zoom = 0;
        return (0);
    }
    sfView_zoom(game->view, 1 + zoom);
    return (0);
}

int rotate_view(float rotate, game_t *game)
{
    sfView_rotate(game->view, rotate);
    return (0);
}

int reset_zoom(game_t *game)
{
    game->zoom = 10;
    sfView_reset(game->view, game->view_rect);
    sfView_setCenter(game->view, game->view_pos);
    zoom_view(-0.5987369392383789, game);
    return (0);
}
