/*
** EPITECH PROJECT, 2022
** myRPG [WSL: Ubuntu]
** File description:
** texts_list
*/

#include "global.h"

text_t **array_of_texts(game_t *game, text_t **texts)
{
    texts[0] = init_text(int_to_str(game->music->volume), MENU_FONT, \
    ((sfVector2f){200, 300}));
    texts[1] = init_text(int_to_str(game->sound->volume), MENU_FONT, \
    ((sfVector2f){200, 350}));
    texts[2] = NULL;
    return (texts);
}

text_t **array_of_texts_main_menu()
{
    text_t **texts = malloc(sizeof(text_t *) * 2);

    texts[0] = init_text("SLIME SURVIVOR", TITLE_FONT, \
    ((sfVector2f){100, 150}));
    texts[1] = NULL;
    return (texts);
}
