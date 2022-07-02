/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** menu_choosing
*/

#include "global.h"
#include <stdio.h>

int play_game(game_t *game)
{
    return my_rpg_game(game);
}

int display_htp(game_t *game)
{
    menu_htp(game);
    return 0;
}

int display_settings(game_t *game)
{
    menu_settings(game);
    return 0;
}

int quit_game(game_t *game)
{
    sfRenderWindow_close(game->Window->window);
    return 0;
}

int (*func_ptr[])(game_t *game) = {
    play_game,
    display_htp,
    display_settings,
    quit_game
};

int check_click_on_button(game_t *game, button_t **buttons,
sfMouseButtonEvent event)
{
    int i = 0;
    int counter = 0;
    sfVector2i mouse_pos = (sfVector2i){event.x, event.y};
    sfVector2u window_size = sfRenderWindow_getSize(game->Window->window);
    sfVector2f init_size = {game->Window->res_x, game->Window->res_y};
    sfVector2f ratio = {(float)window_size.x / \
    init_size.x ,(float)window_size.y / init_size.y};

    while (buttons[counter] != NULL) {
        counter++;
    }
    while (i != counter) {
        if ( mouse_pos.x > buttons[i]->pos.x * ratio.x && mouse_pos.x < \
        buttons[i]->pos.x + 100 * ratio.x && mouse_pos.y > buttons[i]->pos.y \
        * ratio.y && mouse_pos.y < buttons[i]->pos.y * ratio.y + 50)
            if ((func_ptr[i](game)) == 2)
                return (2);
        i++;
    }
    return 1;
}
