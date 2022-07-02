/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** rain_particles
*/

#include "global.h"

int create_rain_particles(game_t *game)
{
    particle_t *particle = malloc(sizeof(particle_t));
    float rand_scale = rand() % 3;

    particle->sprite = sfSprite_create();
    particle->texture = sfTexture_createFromFile\
    ("ressources/particles/trait_blanc.png", NULL);
    if (particle == NULL || particle->texture == NULL || particle-> sprite ==
    NULL)
        return 84;
    sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
    particle->pos = ((sfVector2f)\
    {.x = game->view_pos.x + 250 - rand() % 500 , \
    .y = game->view_pos.y - 250});
    particle->lifetime = 50;
    sfSprite_setPosition(particle->sprite, particle->pos);
    sfSprite_setScale(particle->sprite, (sfVector2f)\
    {rand_scale / 4, rand_scale * -1});
    sfSprite_setColor(particle->sprite, (sfColor){200, 200, 250, 200});
    game->rain = add_end_node(game->rain, particle);
    return 0;
}

int update_rain_particle(game_t *game)
{
    particle_t *particle = NULL;
    linked_list_t *index = game->rain;

    if (index == NULL)
        return 0;
    particle = index->data;
    while (index != NULL) {
        particle = index->data;
        particle->pos.y += (rand() % 50);
        particle->pos.x -= (rand() % 3);
        sfSprite_setPosition(particle->sprite, particle->pos);
        index = index->next;
        particle->lifetime -= 1;
    }
    return 0;
}

int draw_rain_particle(game_t *game)
{
    particle_t *particle = NULL;
    linked_list_t *index = game->rain;

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

int destroy_rain_particles(game_t *game)
{
    if (game == NULL)
        return 0;
    if (game->rain == NULL)
        return 0;
    while (game->rain != NULL &&
    ((particle_t *)(game->rain->data))->lifetime <= 0) {
        sfSprite_destroy(((particle_t *)game->rain->data)->sprite);
        sfTexture_destroy(((particle_t *)game->rain->data)->texture);
        game->rain = remove_first_node(game->rain);
    }
    return 0;
}

int destroy_all_rain_particles(game_t *game)
{
    if (game == NULL)
        return 0;
    if (game->rain == NULL)
        return 0;
    while (game->rain != NULL) {
        sfSprite_destroy(((particle_t *)game->rain->data)->sprite);
        sfTexture_destroy(((particle_t *)game->rain->data)->texture);
        game->rain = remove_first_node(game->rain);
    }
    return 0;
}
