/*
** EPITECH PROJECT, 2018
** strlen.c
** File description:
** strlen
*/

#include <stddef.h>

int my_strlen(char *str)
{
    int n = 0;

    if (str == NULL)
        return (0);
    while (str[n] != '\0')
        n++;
    return (n);
}
