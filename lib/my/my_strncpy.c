/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** cpy n
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int y = 0;

    while (y < n && src[y] != '\0') {
        dest[y] = src[y];
        y++;
    }
    dest[y] = '\0';
    return (dest);
}
