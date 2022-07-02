/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** menu_settings
*/

#include "global.h"

int menu_pause(game_t *game)
{
    sfEvent event;
    background_t bg = {sfSprite_create(), sfTexture_createFromFile \
    (BACKGROUND_HTP, NULL)};
    button_t **buttons = array_of_buttons_pause();
    bool lock_click = false;

    while (sfRenderWindow_isOpen(game->Window->window)) {
        while (sfRenderWindow_pollEvent(game->Window->window, &event))
                analyse_event(game, event);
        if (event.type == sfEvtMouseButtonPressed && !lock_click) {
            lock_click = true;
            play_sound_effect_merp(game);
            check_click_on_button_pause(game, buttons, event.mouseButton);
        }
        if (event.type == sfEvtMouseButtonReleased)
            lock_click = false;
        display_hud(game, &bg, buttons);
        sfRenderWindow_display(game->Window->window);
    }
    return 0;
}
