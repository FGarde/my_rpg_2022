/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** menu_settings
*/

#include "global.h"

void display_special_hud_settings(game_t *game, text_t **texts)
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

int menu_settings(game_t *game)
{
    sfEvent event;
    background_t bg = {sfSprite_create(), sfTexture_createFromFile \
    (BACKGROUND_SETTINGS, NULL)};
    button_t **buttons = array_of_buttons_settings();
    text_t **texts = malloc(sizeof(text_t *) * 3);
    bool lock_click = false;

    texts = array_of_texts(game, texts);
    while (sfRenderWindow_isOpen(game->Window->window)) {
        while (sfRenderWindow_pollEvent(game->Window->window, &event))
                analyse_event(game, event);
        if (event.type == sfEvtMouseButtonPressed && !lock_click) {
            lock_click = true;
            play_sound_effect_merp(game);
            check_click_on_button_settings(game, buttons, event.mouseButton);
            texts = array_of_texts(game, texts);
        }
        if (event.type == sfEvtMouseButtonReleased)
            lock_click = false;
        display_hud(game, &bg, buttons);
        display_special_hud_settings(game, texts);
        sfRenderWindow_display(game->Window->window);
    }
    return 0;
}
