/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** rain
*/

#include "global.h"

int rain_gestion(game_t *game)
{
    sfColor shadow = (sfColor){150, 150, 150, 255};
    sfColor light = (sfColor){255, 255, 255, 255};

    if (game->raining == true) {
        sfSprite_setColor(game->maps->map_sprite, shadow);
        sfSprite_setColor(game->maps->map_sprite_3d, shadow);
        if (game->character->vulnerable == true)
            sfSprite_setColor(game->character->sprite, shadow);
        create_rain_particles(game);
        create_rain_particles(game);
        create_rain_particles(game);
    } else {
        sfSprite_setColor(game->maps->map_sprite, light);
        sfSprite_setColor(game->maps->map_sprite_3d, light);
        if (game->character->vulnerable == true)
            sfSprite_setColor(game->character->sprite, light);
    }
    return 0;
}
