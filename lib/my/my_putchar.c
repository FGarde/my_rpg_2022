/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** my_putchar
*/

#include "my_lib.h"

int my_putchar(char const c)
{
    write(1, &c, 1);
    return (0);
}
