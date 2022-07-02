/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** main_menu
*/
#include <stdio.h>
#include "global.h"

void display_special_hud_main_menu(game_t *game, text_t **texts)
{
    int i = 0;
    int cpt = 0;

    while (texts[cpt] != NULL)
        cpt++;
    while (i != cpt) {
        sfRenderWindow_drawText(game->Window->window, texts[i]->text, NULL);
        i++;
    }
}

int main_menu(game_t *game)
{
    sfEvent event;
    background_t bg = {sfSprite_create(), sfTexture_createFromFile \
    (BACKGROUND_MAIN_MENU, NULL)};
    button_t **buttons = array_of_buttons();
    text_t **texts = array_of_texts_main_menu();
    bool lock_click = false;

    while (sfRenderWindow_isOpen(game->Window->window)) {
        while (sfRenderWindow_pollEvent(game->Window->window, &event))
                analyse_event(game, event);
        if (event.type == sfEvtMouseButtonPressed && !lock_click) {
            lock_click = true;
            play_sound_effect_merp(game);
            check_click_on_button(game, buttons, event.mouseButton);
        }
        if (event.type == sfEvtMouseButtonReleased)
            lock_click = false;
        display_hud(game, &bg, buttons);
        display_special_hud_main_menu(game, texts);
        sfRenderWindow_display(game->Window->window);
    }
    return 0;
}
