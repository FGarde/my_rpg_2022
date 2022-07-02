/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde [WSL: Ubuntu]
** File description:
** resolution
*/

#include "global.h"

window_t *resize_window(window_t *window)
{
    int i = window->resolution;
    sfVector2u *window_sizes_tab;

    window_sizes_tab = malloc(sizeof(sfVector2u) * 3);
    window_sizes_tab[0] = (sfVector2u){800, 600};
    window_sizes_tab[1] = (sfVector2u){1280, 720};
    window_sizes_tab[2] = (sfVector2u){1920, 1080};
    window->resolution++;
    sfRenderWindow_setSize(window->window, window_sizes_tab[i]);
    if (i >= 2)
        window->resolution = 0;
    return window;
}
