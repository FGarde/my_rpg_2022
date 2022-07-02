/*
** EPITECH PROJECT, 2022
** my_RPG
** File description:
** my_lib
*/

#ifndef MY_LIB_H_
    #define MY_LIB_H_

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
int my_get_nbr(char const *str);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_putchar(char const c);
int get_size_int(int nb);
char *int_to_str(int nb);
char **malloc_tab(char *str, char c);
char **my_str_word_to_array(char *str, char c);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);

#endif
