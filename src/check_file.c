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

void debug(tetris_t *tetris)
{
    my_putstr("*** DEBUG MODE ***\nKey Left :  ", 1);
    my_putstr(tetris->debug_info.keys[0], 1);
    my_putstr("\nKey Right :  ", 1);
    my_putstr(tetris->debug_info.keys[1], 1);
    my_putstr("\nKey Turn :  ", 1);
    my_putstr(tetris->debug_info.keys[2], 1);
    my_putstr("\nKey Drop :  ", 1);
    my_putstr(tetris->debug_info.keys[3], 1);
    my_putstr("\nKey Quit :  ", 1);
    my_putstr(tetris->debug_info.keys[4], 1);
    my_putstr("\nKey Pause :  ", 1);
    my_putstr(tetris->debug_info.keys[5], 1);
    my_putstr("\nNext :  ", 1);
    my_putstr(tetris->debug_info.next ? "Yes" : "No", 1);
    my_putstr("\nLevel :  ", 1);
    my_putstr(tetris->debug_info.level, 1);
    my_putstr("\nSize :  ", 1);
    my_putstr(tetris->debug_info.size, 1);
    write(1, "\n", 1);
}

int is_number(char *str)
{
    int status = 0;

    if (str == NULL)
        return (1);
    for (int i = my_strlen_custom(str); i >= 0; i--) {
        if (str[i] == 32 || (str[i] >= 48 && str[i] <= 57)) {
            status++;
        }
    }
    status = my_strlen_custom(str) - status;
    return status;
}

char **tetris_open_read_file(char *path)
{
    char *map;
    int fd;
    struct stat size;

    stat(path, &size);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        exit(write(2, "need file\n", 10));
    map = malloc(sizeof(char) * size.st_size + 1);
    if (!map)
        exit(write(2, "malloc crashed\n", 15));
    read(fd, map, size.st_size + 1);
    map[size.st_size + 1] = '\0';
    return (str_to_tab(map, '\n'));
}

int check_file(char *str, tetris_t *tet)
{
    char *cpy = my_str_dup(str);
    char *name = find_name(my_str_dup(str));
    int status = 0;
    char **file = tetris_open_read_file(cpy);

    if (is_number(file[0]) || put_in_struct(tet, file[0]) ||
    check_tetrimino(tet, file))
        status = 1;
    print_info(file, status, tet, name);
    free(cpy);
    return (0);
}
