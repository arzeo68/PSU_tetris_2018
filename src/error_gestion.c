/*
** EPITECH PROJECT, 2019
** EPITECH
** File description:
** tetris
*/

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../include/my.h"

char *find_name(char *str)
{
    char **tab = str_to_tab(str, '/');
    char **tab_name = str_to_tab(tab[1], '.');

    return (tab_name[0]);
}

int print_info(char **file, int status, tetris_t *tet, char *str)
{
    int i = 1;
    my_putstr("Tetriminos :  Name ", 1);
    my_putstr(str, 1);
    if (status == 1) {
        write(1, " :  Error\n", 10);
        return (1);
    }
    my_putstr(" :  Size ", 1);
    my_put_nbr(tet->info[0]);
    my_putchar('x');
    my_put_nbr(tet->info[1]);
    my_putstr(" :  Color ", 1);
    my_put_nbr(tet->info[2]);
    my_putstr(" :\n", 1);
    for (i; file[i + 1]; i++) {
        my_putstr(file[i], 1);
        my_putchar('\n');
    }
    my_putstr(file[i], 1);
    return (0);
}

int check_lengh(char *str)
{
    int lengh = 0;
    int i = my_strlen_custom(str);

    while (str[i] != '*')
        i--;
    while (i >= 0) {
        lengh++;
        i--;
    }
    return (lengh);
}

int check_tetrimino(tetris_t *tet, char **shape)
{
    int max = 0;
    int heigh = 0;
    int tmp = 0;

    for (int i = 1; shape[i]; i++, heigh++) {
        tmp = check_lengh(shape[i]);
        if (tmp >= max) {
            max = tmp;
        }
    }
    if (max == tet->info[0] && heigh == tet->info[1])
        return (0);
    return (84);
}

int put_in_struct(tetris_t *tet, char *str)
{
    int value = 0;
    int size = 0;
    char **arg = str_to_tab(str, ' ');

    for (int i = 0; arg[i]; i++, size++);
    if (size < 3 || size > 3)
        return (84);
    for (int i = 0; i <= 2; i++) {
        tet->info[i] = my_getnbr(arg[i]);
    }
    value = tet->info[2] > 7 || tet->info[2] < 0 ? 84 : 0;
    return (value);
}