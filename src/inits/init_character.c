/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** init_character
*/

#include "global.h"

game_t *init_character_last(game_t *game)
{
    sfSprite_setTextureRect(game->character->sprite, game->character->rect);
    game->character->clock = sfClock_create();
    game->character->clock_attack = sfClock_create();
    game->character->hitbox = (sfIntRect){game->view_pos.x - 6, \
    game->view_pos.y, 12, -24};
    game->character->life = 5;
    game->character->damage = 1;
    game->character->moving = false;
    game->character->vulnerable = true;
    game->character->attack_speed = 1500000;
    return game;
}

int init_character(game_t *game)
{
    game->character = malloc(sizeof(character_t));
    game->character->sprite = sfSprite_create();
    game->character->texture = sfTexture_createFromFile\
    ("ressources/characters/hero.png", NULL);
    game->character->direction = 2;
    sfSprite_setTexture(game->character->sprite, \
    game->character->texture, sfFalse);
    sfSprite_setPosition(game->character->sprite, (sfVector2f)\
    {game->view_pos.x - 6, game->view_pos.y - 10});
    sfSprite_setScale(game->character->sprite, (sfVector2f){0.70, 0.70});
    game->character->rect = (sfIntRect){3, 7, 16, 30};
    game->character->rect.top = 7 + game->character->direction * (28 + 4);
    game = init_character_last(game);
    return 0;
}
