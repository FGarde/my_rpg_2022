/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** hero_attacks
*/

#include "global.h"

void vulnerability_update(game_t *game)
{
    if (game->character->vulnerable == false) {
        sfSprite_setColor(game->character->sprite, sfRed);
    } else {
        if (game->raining == false)
            sfSprite_setColor(game->character->sprite, sfWhite);
    }
    return;
}
