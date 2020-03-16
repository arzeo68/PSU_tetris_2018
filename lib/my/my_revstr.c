/*
** EPITECH PROJECT, 2018
** revstr
** File description:
** revstr
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    char c;
    int j = 0;
    int len;

    len = i = my_strlen(str);
    for (j = 0; j < i - 1; j++) {
        c = str[j];
        str[j] = str[i - 1];
        str[i - 1] = c;
        i--;
    }
    str[len] = '\0';
    return (str);
}
