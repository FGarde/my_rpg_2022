/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** rain_particles
*/

#include "global.h"

int create_enemy(game_t *game, int level)
{
    character_t *particle;
    sfColor on = sfBlack;
    sfVector2f pos = (sfVector2f){0, 0};

    if (len_list(game->enemies) >= 15)
        return (0);
    particle = malloc(sizeof(character_t));
    particle->sprite = sfSprite_create();
    particle->texture = sfTexture_createFromFile\
    ("ressources/characters/enemies.png", NULL);
    if (particle == NULL || particle->texture == NULL || particle-> sprite ==
    NULL)
        return 84;
    sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
    while (on.r != sfWhite.r && on.g != sfWhite.g && on.b != sfWhite.b) {
        pos.x = rand() % 1750;
        pos.y = rand() % 1200;
        on = sfImage_getPixel(game->maps->map_collision, \
        pos.x + (24 * 0.35), pos.y + (51 * 0.35));
    }
    particle->pos = pos;
    particle->life = 3 * level;
    particle->rect = (sfIntRect){247, 69, 48, 56};
    particle->hitbox = (sfIntRect){particle->pos.x - 6, particle->pos.y, \
    12, -16};
    sfSprite_setTextureRect(particle->sprite, particle->rect);
    sfSprite_setPosition(particle->sprite, particle->pos);
    sfSprite_setScale(particle->sprite, (sfVector2f){0.35, 0.35});
    game->enemies = add_end_node(game->enemies, particle);
    return 0;
}

int update_enemy(game_t *game)
{
    character_t *particle = NULL;
    linked_list_t *index = game->enemies;

    if (index == NULL)
        return 0;
    particle = index->data;
    while (index != NULL) {
        particle = index->data;
        if (particle->pos.y < game->view_pos.y)
            particle->pos.y += 1;
        else
            particle->pos.y -= 1;
        if (particle->pos.x < game->view_pos.x)
            particle->pos.x += 1;
        else
            particle->pos.x -= 1;
        particle->rect.left += 49;
        if (particle->rect.left >= 295)
            particle->rect.left = 2;
        particle->hitbox.left = particle->pos.x - 6;
        particle->hitbox.top = particle->pos.y;
        if (sfIntRect_intersects(&(particle->hitbox), \
        &(game->character->hitbox), NULL) == sfTrue
        && game->character->vulnerable == true) {
            game->character->life -= 1;
            game->character->vulnerable = false;
        }
        sfSprite_setTextureRect(particle->sprite, particle->rect);
        sfSprite_setPosition(particle->sprite, particle->pos);
        index = index->next;
    }
    return 0;
}

int draw_enemy(game_t *game)
{
    character_t *particle = NULL;
    linked_list_t *index = game->enemies;

    if (index == NULL)
        return 0;
    while (index != NULL) {
        particle = index->data;
        sfRenderWindow_drawSprite(game->Window->window, \
        particle->sprite, NULL);
        index = index->next;
    }
    return 0;
}

int destroy_enemy(game_t *game)
{
    linked_list_t *tmp = game->enemies;
    linked_list_t *prev = game->enemies;
    linked_list_t *head = game->enemies;

    if (game == NULL)
        return 0;
    if (game->enemies == NULL)
        return 0;
    while (tmp != NULL && head != NULL) {
        if (((character_t *)(head->data))->life <= 0) {
            prev = prev->next;
            head = head->next;
            sfSprite_destroy(((character_t *)tmp->data)->sprite);
            sfTexture_destroy(((character_t *)tmp->data)->texture);
            tmp = remove_first_node(tmp);
        } else if (((character_t *)(tmp->data))->life <= 0) {
            prev->next = tmp->next;
            sfSprite_destroy(((character_t *)tmp->data)->sprite);
            sfTexture_destroy(((character_t *)tmp->data)->texture);
            tmp = remove_first_node(tmp);
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    game->enemies = head;
    return 0;
}

int destroy_all_enemy(game_t *game)
{
    if (game == NULL)
        return 0;
    if (game->enemies == NULL)
        return 0;
    while (game->enemies != NULL) {
        sfSprite_destroy(((character_t *)game->enemies->data)->sprite);
        sfTexture_destroy(((character_t *)game->enemies->data)->texture);
        game->enemies = remove_first_node(game->enemies);
    }
    return 0;
}
