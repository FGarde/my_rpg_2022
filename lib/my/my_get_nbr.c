/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** get number
*/

int my_get_nbr(char const *str)
{
    int nbr = 0;
    int i = 0;
    int len = 0;
    int min = -2146483648;
    int max = 2147483647;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            nbr = nbr * 10;
            nbr = nbr + (str[i] - '0');
            i += 1;
            len += 1;
        } else {
            i += 1;
        }
    }
    if (str[i - len - 1] == '-')
        nbr = -nbr;
    return nbr;
}
