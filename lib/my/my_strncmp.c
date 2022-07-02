/*
** EPITECH PROJECT, 2021
** my_strncmp.c
** File description:
** ncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; ++i) {
        if (s1[i] != s2[i]) {
            return 84;
        }
    }
    return 0;
}
