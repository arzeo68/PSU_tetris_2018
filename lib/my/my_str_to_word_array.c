/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** explode a string to array
*/
#include <string.h>
#include <stdlib.h>

char **str_to_tab(char *str, char separator)
{
    char **tab;
    int len = 1;

    if (!str)
        return (NULL);
    for (int i = 0; str[i]; i++)
        len += str[i] == separator;
    tab = malloc((len + 1) * sizeof(char *));
    if (!tab)
        return (NULL);
    for (int i = 1, j = 0; str[i]; i++) {
        if (i == 1)
            tab[j++] = &str[0];
        else if (str[i - 1] == separator)
            tab[j++] = &str[i];
        str[i - 1] = str[i - 1] == separator ? 0 : str[i - 1];
    }
    tab[len] = NULL;
    return (tab);
}
