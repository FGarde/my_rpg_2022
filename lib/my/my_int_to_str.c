/*
** EPITECH PROJECT, 2022
** my_int_to_str
** File description:
** converts an int to an str
*/

#include "my_lib.h"

int get_size_int(int nb)
{
    int count = 0;

    while (nb > 0) {
        count++;
        nb /= 10;
    }
    return count;
}

char *int_to_str(int nb)
{
    int size_nb = get_size_int(nb);
    char *str = malloc(sizeof(char) * size_nb + 1);
    int i = 1;

    while (nb > 0) {
        str[size_nb - i] = nb % 10 + '0';
        i++;
        nb /= 10;
    }
    str[size_nb] = '\0';
    return str;
}
