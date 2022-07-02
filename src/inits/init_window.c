/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** init_window
*/

#include "global.h"

window_t *init_window(window_t *window)
{
    window->name = "my_RPG";
    window->fps = 30;
    window->res_x = 800;
    window->res_y = 600;
    window->mode = (sfVideoMode){window->res_x, window->res_y, window->fps};
    window->resolution = 0;
    window->window = sfRenderWindow_create(window->mode, window->name, \
    sfResize|sfClose, NULL);
    return window;
}
