/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** backgrounds
*/

#include "global.h"

int display_background(game_t *game, background_t *bg)
{
    if (!bg->texture || !bg->sprite)
        return (84);
    sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
    sfRenderWindow_drawSprite(game->Window->window, bg->sprite, NULL);
    return (0);
}
