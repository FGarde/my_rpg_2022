/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** menu_management
*/

#include "global.h"

void display_buttons(game_t *game , button_t **buttons)
{
    int i = 0;
    int cpt = 0;

    while (buttons[cpt] != NULL)
        cpt++;
    while (i != cpt) {
        sfRenderWindow_drawText(game->Window->window, buttons[i]->text, NULL);
        i++;
    }
}

void display_hud(game_t *game, background_t *bg, button_t **buttons)
{
    display_background(game, bg);
    display_buttons(game, buttons);
}
