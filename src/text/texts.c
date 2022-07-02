/*
** EPITECH PROJECT, 2022
** myRPG [WSL: Ubuntu]
** File description:
** texts
*/

#include "global.h"

text_t *init_text(char *word, char *font, sfVector2f pos)
{
    text_t *text = malloc(sizeof(text_t));

    text->font = sfFont_createFromFile(font);
    text->text = sfText_create();
    text->pos = pos;
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 30);
    sfText_setString(text->text, word);
    sfText_setColor(text->text, sfWhite);
    sfText_setPosition(text->text, text->pos);
    sfText_setOutlineThickness(text->text, 1);
    return text;
}
