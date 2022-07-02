/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** menu_settings_select
*/

#include "global.h"

void sound_management(game_t *game)
{
    update_music(game->music);
}

void effect_management(game_t *game)
{
    update_sound(game->sound);
}

void resolution_managent(game_t *game)
{
    resize_window(game->Window);
}

void quit_settings(game_t *game)
{
    main_menu(game);
}

void (*func_ptr_settings[])(game_t *game) = {
    sound_management,
    effect_management,
    resolution_managent,
    quit_settings
};

int check_click_on_button_settings(game_t *game, button_t **buttons,
sfMouseButtonEvent event)
{

    int i = 0;
    int counter = 0;
    sfVector2i mouse_pos = (sfVector2i){event.x, event.y};
    sfVector2u window_size = sfRenderWindow_getSize(game->Window->window);
    sfVector2f init_size = {game->Window->res_x, game->Window->res_y};
    sfVector2f ratio = {(float)window_size.x / init_size.x ,\
    (float)window_size.y / init_size.y};

    while (buttons[counter] != NULL)
        counter++;
    while (i != counter) {
        if (mouse_pos.x > buttons[i]->pos.x * ratio.x && mouse_pos.x < \
            buttons[i]->pos.x + 100 * ratio.x && mouse_pos.y > \
            buttons[i]->pos.y * ratio.y && mouse_pos.y < buttons[i]->pos.y\
            * ratio.y + 50) {
                (func_ptr_settings[i](game));
            }
            i++;
        }
    return 1;
}
