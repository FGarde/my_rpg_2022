/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** menu_choosing
*/

#include "global.h"
#include <stdio.h>

void pause_to_play(game_t *game)
{
    game->paused = false;
}

void settings_pause(game_t *game)
{
    menu_settings(game);
}

void pause_to_main_menu(game_t *game)
{
    menu_settings(game);
}

void (*func_ptr_pause[])(game_t *game) = {
    pause_to_play,
    settings_pause,
    pause_to_main_menu,
};

int check_click_on_button_pause(game_t *game, button_t **buttons,
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
            (func_ptr_pause[i](game));
        i++;
    }
    return 1;
}
