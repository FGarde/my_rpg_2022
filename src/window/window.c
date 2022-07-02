/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** window
*/

#include "global.h"

int draw_hud(game_t *game)
{
    sfRenderWindow_setView(game->Window->window, game->hud_view);
    sfRenderWindow_drawSprite(game->Window->window, game->sprite_life, NULL);
    sfRenderWindow_setView(game->Window->window, game->view);

    return 0;
}

int display(game_t *game)
{
    sfRenderWindow_clear(game->Window->window, sfBlack);
    sfRenderWindow_setView(game->Window->window, game->view);
    sfRenderWindow_drawSprite(game->Window->window, game->maps->map_sprite, \
    NULL);
    if (draw_particle(game) != 0)
        return 84;
    sfRenderWindow_drawSprite(game->Window->window, game->character->sprite, \
    NULL);
    draw_enemy(game);
    sfRenderWindow_drawSprite(game->Window->window, game->maps->map_sprite_3d,\
    NULL);
    if (draw_rain_particle(game) != 0)
        return 84;
    draw_hud(game);
    sfRenderWindow_display(game->Window->window);
    return 0;
}

int rpg_menu(void)
{
    game_t *game = malloc(sizeof(game_t));
    window_t *window = malloc(sizeof(window_t));
    music_t *music = malloc(sizeof(music_t));
    sound_t *sound = malloc(sizeof(sound_t));

    window = init_window(window);
    game = init_game(game, window);
    game->music = init_music(music);
    game->sound = init_sound(sound);
    game->Window = window;
    main_menu(game);
    destroy_all(game);
    return 0;
}
