/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** game_loop
*/

#include"global.h"

int update_particles(game_t *game)
{
    if (sfClock_getElapsedTime(game->particle_clock).microseconds >= 100000) {
        if (game->character->moving == true)
            create_particles(game);
        rain_gestion(game);
        if (update_particle(game) != 0)
            return 84;
        if (update_rain_particle(game) != 0)
            return 84;
        if (destroy_particles(game) != 0)
            return 84;
        if (destroy_rain_particles(game) != 0)
            return 84;
        if (rand() % 1000 == 0)
            game->raining = !game->raining;
        sfClock_restart(game->particle_clock);
    }
    return 0;
}

int update_enemy_clock(game_t *game)
{
    if (sfClock_getElapsedTime(game->enemy_clock).microseconds >= 300000) {
        create_enemy(game, 1);
        if (game->character->vulnerable == false) {
            game->character->vulnerable = true;
        }
        sfClock_restart(game->character->clock_attack);
        update_enemy(game);
        destroy_enemy(game);
        sfClock_restart(game->enemy_clock);
    }
    return 0;
}

int attacks(game_t *game)
{
    game->rect_life.width = game->character->life * 254;
    sfSprite_setTextureRect(game->sprite_life, game->rect_life);
    return 0;
}

int my_rpg_game(game_t *game)
{
    play_background_music(game);
    if (game->paused) {
            menu_pause(game);
        }
    while (sfRenderWindow_isOpen(game->Window->window)) {
        event_loop(game);
        if (!game->paused) {
            update_animation(game);
            attacks(game);
            update_particles(game);
            update_enemy_clock(game);
            vulnerability_update(game);
            display(game);
        }
        if (game->character->life <= 0) {
            destroy_all(game);
            exit(0);
        }
    }
    return 0;
}
