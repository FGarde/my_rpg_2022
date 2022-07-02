/*
** EPITECH PROJECT, 2022
** my_get_words
** File description:
** str > array
*/

#include "my_lib.h"

char **malloc_tab(char *str, char c)
{
    int cpt = 0;
    char **tab = NULL;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            cpt++;
    }
    tab = malloc(sizeof(char *) * (cpt + 2));
    return tab;
}

char **my_str_word_to_array(char *str, char c)
{
    char **tab = malloc_tab(str, c);
    int cpt = 0;
    int k = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        while (str[j] != c && str[j] != '\0') {
            cpt++;
            j++;
        }
        tab[k] = malloc(sizeof(char) * (cpt + 1));
        my_strncpy(tab[k], &str[j - cpt], cpt);
        tab[k][cpt + 1] = '\0';
        cpt = 0;
        k++;
    }
    tab[k] = NULL;
    return tab;
}
