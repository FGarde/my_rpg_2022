/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** main
*/

#include "global.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1) {
        check_help(av);
        return 0;
    }
    if (check_env(env))
        return 84;
    rpg_menu();
    return 0;
}
