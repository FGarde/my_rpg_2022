/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** destroy_global
*/

#include "global.h"

int destroy_all(game_t *game)
{
    destroy_all_particles(game);
    destroy_all_rain_particles(game);
    destroy_all_enemy(game);
    destroy_game(game);
    return (0);
}
