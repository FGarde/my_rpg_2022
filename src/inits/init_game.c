/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** init_game
*/

#include "global.h"

int init_collision(game_t *game)
{
    game->maps->map_collision = sfImage_createFromFile\
    ("ressources/maps/map_collisions.png");
    return 0;
}

game_t *init_game_last(game_t *game)
{
    game->enemy_clock = sfClock_create();
    game->sprite_life = sfSprite_create();
    game->texture_life = sfTexture_createFromFile\
    ("ressources/characters/life.png", NULL);
    game->rect_life = (sfIntRect){0, 0, 1270, 254};
    sfSprite_setTexture(game->sprite_life, game->texture_life, sfFalse);
    sfSprite_setPosition(game->sprite_life, (sfVector2f)\
    {-1000, -1000});
    sfSprite_setScale(game->sprite_life, (sfVector2f){0.1, 0.1});
    sfSprite_setTextureRect(game->sprite_life, game->rect_life);
    init_character(game);
    init_collision(game);
    zoom_view(-0.5987369392383789, game);
    return game;
}

game_t *init_game(game_t *game, window_t *window)
{
    game->Window = window;
    game->maps = init_map();
    game->view_rect = (sfFloatRect){0, 0, game->Window->res_x, \
    game->Window->res_y};
    game->view_pos = (sfVector2f){575 , 750};
    game->view = sfView_createFromRect(game->view_rect);
    game->hud_view = sfView_createFromRect(game->view_rect);
    sfView_setCenter(game->view, game->view_pos);
    sfView_setCenter(game->hud_view, (sfVector2f){-650, -710});
    game->clock = sfClock_create();
    game->zoom = 10;
    game->particle_clock = sfClock_create();
    game->paused = false;
    game->raining = true;
    game = init_game_last(game);
    return game;
}
