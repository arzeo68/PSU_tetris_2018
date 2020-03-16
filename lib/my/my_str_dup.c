/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** str duplicate
*/

#include "../../include/my.h"

char *my_str_dup(char *str)
{
    char *str_dup = NULL;

    if (str == NULL)
        return (NULL);
    str_dup = malloc(sizeof(char) * my_strlen(str) + 1);
    for (int i = 0; str[i]; i++)
        str_dup[i] = str[i];
    str_dup[my_strlen(str)] = '\0';
    return (str_dup);
}
