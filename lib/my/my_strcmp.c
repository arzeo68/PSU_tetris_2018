/*
** EPITECH PROJECT, 2018
** cmp
** File description:
** cmp
*/

#include <stddef.h>
#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (0);
    while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        i = i + 1;
    return (s1[i] - s2[i]);
}
