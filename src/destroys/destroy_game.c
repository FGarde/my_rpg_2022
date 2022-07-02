/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** destroy_game
*/

#include "global.h"

int destroy_game(game_t *game)
{
    sfSprite_destroy(game->character->sprite);
    sfSprite_destroy(game->maps->map_sprite);
    sfSprite_destroy(game->maps->map_sprite_3d);
    sfTexture_destroy(game->maps->map_texture);
    sfTexture_destroy(game->maps->map_texture_3d);
    sfTexture_destroy(game->character->texture);
    sfImage_destroy(game->maps->map_collision);
    sfClock_destroy(game->clock);
    sfClock_destroy(game->particle_clock);
    sfClock_destroy(game->character->clock);
    free(game->character);
    free(game->maps);
    sfRenderWindow_destroy(game->Window->window);
    free(game);
    return 0;
}
