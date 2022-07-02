/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Reproduce strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int diff = 0;
    char x = 0;
    char y = 0;

    while (s1[i] != '\0') {
        x = s1[i];
        i += 1;
    }
    while (s2[j] != '\0') {
        y = s2[j];
        j += 1;
    }
    diff = x-y;
    return (diff);
}
