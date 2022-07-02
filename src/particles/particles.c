/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** particles
*/

#include "global.h"

int create_particles(game_t *game)
{
    particle_t *particle = malloc(sizeof(particle_t));

    particle->sprite = sfSprite_create();
    particle->texture = sfTexture_createFromFile\
    ("ressources/particles/rond_blanc.png", NULL);
    if (particle == NULL || particle->texture == NULL || particle-> sprite ==
    NULL)
        return 84;
    sfSprite_setTexture(particle->sprite, particle->texture, sfFalse);
    particle->pos = ((sfVector2f)\
    {.x = game->view_pos.x + rand() % 5, .y = game->view_pos.y + 8});
    particle->lifetime = 15;
    sfSprite_setPosition(particle->sprite, particle->pos);
    sfSprite_setScale(particle->sprite, (sfVector2f){0.2, 0.2});
    sfSprite_setColor(particle->sprite, (sfColor){255, 255, 210, 150});
    game->particles = add_end_node(game->particles, particle);
    return 0;
}

int update_particle(game_t *game)
{
    particle_t *particle = NULL;
    linked_list_t *index = game->particles;

    if (index == NULL)
        return 0;
    particle = index->data;
    while (index != NULL) {
        particle = index->data;
        particle->pos.y -= (rand() % 2);
        particle->pos.x -= (rand() % 3);
        sfSprite_setPosition(particle->sprite, particle->pos);
        index = index->next;
        particle->lifetime -= 1;
    }
    return 0;
}

int draw_particle(game_t *game)
{
    particle_t *particle = NULL;
    linked_list_t *index = game->particles;

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

int destroy_particles(game_t *game)
{
    if (game == NULL)
        return 0;
    if (game->particles == NULL)
        return 0;
    while (game->particles != NULL &&
    ((particle_t *)(game->particles->data))->lifetime <= 0) {
        sfSprite_destroy(((particle_t *)game->particles->data)->sprite);
        sfTexture_destroy(((particle_t *)game->particles->data)->texture);
        game->particles = remove_first_node(game->particles);
    }
    return 0;
}

int destroy_all_particles(game_t *game)
{
    if (game == NULL)
        return 0;
    if (game->particles == NULL)
        return 0;
    while (game->particles != NULL) {
        sfSprite_destroy(((particle_t *)game->particles->data)->sprite);
        sfTexture_destroy(((particle_t *)game->particles->data)->texture);
        game->particles = remove_first_node(game->particles);
    }
    return 0;
}
