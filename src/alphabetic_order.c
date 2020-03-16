/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** alphabetical
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <getopt.h>
#include <ncurses.h>
#include "settings.h"
#include "struct.h"
#include "my.h"

int my_strlen_custom(char *str)
{
    int n = 0;

    if (str == NULL)
        return (0);
    while (str[n] != '\n' && str[n] != '\0')
        n++;
    return (n);
}

static char *my_strcat_custom(char *to_add, char *str)
{
    char *new = NULL;
    int i = 0;
    int j = 0;

    if (!to_add)
        return (str);
    new = malloc(sizeof(char) * (my_strlen(to_add) + my_strlen(str) + 4));
    if (!new)
        return (NULL);
    if (str)
        for (; str[i]; i++)
            new[i] = str[i];
    new[i] = ':';
    i++;
    for (; to_add[j]; j++)
        new[i + j] = to_add[j];
    new[i + j] = '\0';
    return (new);
}

static int swap_tab(char ***tab, int move)
{
    char *save = NULL;

    for (int i = 0; (*tab)[i + 1]; i++) {
        if (my_strcmp((*tab)[i], (*tab)[i + 1]) > 0) {
            save = my_str_dup((*tab)[i]);
            (*tab)[i] = my_str_dup((*tab)[i + 1]);
            (*tab)[i + 1] = my_str_dup(save);
            move++;
        }
    }
}

static char **sort_tetri(char **tab)
{
    unsigned short move = 1;

    while (move != 0) {
        move = 0;
        move = swap_tab(&tab, move);
    }
    return (tab);
}

void put_in_tab(tetris_t *tetris)
{
    char **tab = NULL;
    DIR *directory = opendir("tetriminos");
    struct dirent *read;
    char *all = NULL;
    char *file_path = NULL;
    while ((read = readdir(directory)) != NULL) {
        if (read->d_name[0] == '.')
            continue;
        if (all != NULL)
            all = my_strcat_custom(read->d_name, all);
        else
            all = read->d_name;
    }
    tab = str_to_tab(all, ':');
    tab = sort_tetri(tab);
    for (int i = 0; tab[i]; i++) {
        file_path = malloc(sizeof(char) * (my_strlen(tab[i]) + 12));
        my_strcat(file_path, "tetriminos/");
        my_strcat(file_path, tab[i]);
        check_file(file_path, tetris);
    }
}