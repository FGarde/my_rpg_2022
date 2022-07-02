/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** error
*/

#include "global.h"

int my_puterror(char *str)
{
    write(2, str, my_strlen(str));
    return 0;
}

int check_env(char **env)
{
    int check = 0;

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "DISPLAY=", 8)) {
            check = 1;
        }
        if (my_strncmp(env[i], "TERM=",5)) {
            check = 1;
        }
    }
    if (check == 0) {
        my_puterror("As we said, we see you Epitech test.\n");
        return 84;
    }
    return 0;
}

void help_cmd(void)
{
    my_putstr("👊 Welcome to our 'RPG' game ! 👊\n\n");
    my_putstr("👀 USAGE 👀\n");
    my_putstr("\t./my_rpg\n\n");
    my_putstr("📢 OPTIONS 📢\n\n");
    my_putstr("\t-h : print usage and quit.\n");
    my_putstr("\t To see commands, look at the how to play menu.\n\n");
    my_putstr("❓ INFOS ❓\n\n");
    my_putstr("\t You cannot load the game without an env.\n\n");
}

void check_help(char *av[])
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help_cmd();
    }
}
