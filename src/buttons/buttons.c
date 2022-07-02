/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** buttons
*/

#include "global.h"

button_t *init_button(char *text, char *font, sfVector2f pos)
{
    button_t *button = malloc(sizeof(button_t));

    button->text = sfText_create();
    button->font = sfFont_createFromFile(font);
    button->pos = pos;
    button->i = 1;
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, text);
    sfText_setCharacterSize(button->text, 24);
    sfText_setPosition(button->text, button->pos);
    sfText_setFillColor(button->text, sfWhite);
    sfText_setOutlineColor(button->text, sfBlack);
    sfText_setOutlineThickness(button->text, 4);
    return (button);
}
