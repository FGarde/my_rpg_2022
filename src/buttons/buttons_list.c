/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** button_list
*/

#include "global.h"

button_t **array_of_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    buttons[0] = init_button("Play", MENU_FONT, ((sfVector2f){100, 350}));
    buttons[1] = init_button("How To Play", MENU_FONT, ((sfVector2f)\
    {100, 400}));
    buttons[2] = init_button("Settings", MENU_FONT, ((sfVector2f){100, 450}));
    buttons[3] = init_button("Quit", MENU_FONT, ((sfVector2f){100, 500}));
    buttons[4] = NULL;
    return (buttons);
}

button_t **array_of_buttons_settings(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    buttons[0] = init_button("Music", MENU_FONT, ((sfVector2f){100, 300}));
    buttons[1] = init_button("Effects", MENU_FONT, ((sfVector2f){100, 350}));
    buttons[2] = init_button("Reso", MENU_FONT, ((sfVector2f){100, 400}));
    buttons[3] = init_button("Back", MENU_FONT, ((sfVector2f){100, 450}));
    buttons[4] = NULL;
    return (buttons);
}

button_t **array_of_buttons_htp(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 2);
    buttons[0] = init_button("Back", MENU_FONT, ((sfVector2f){390, 500}));
    buttons[1] = NULL;
    return (buttons);
}

button_t **array_of_buttons_pause(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    buttons[0] = init_button("Play", MENU_FONT, ((sfVector2f){390, 500}));
    buttons[1] = init_button("Settings", MENU_FONT, ((sfVector2f){390, 500}));
    buttons[2] = init_button("Back", MENU_FONT, ((sfVector2f){390, 500}));
    buttons[3] = NULL;
    return (buttons);
}
