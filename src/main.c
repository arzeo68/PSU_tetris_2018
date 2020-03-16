/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <getopt.h>
#include <ncurses.h>
#include <ncurses.h>
#include <term.h>
#include "settings.h"
#include "struct.h"
#include "my.h"


static const param_t PARAM[] = {
    {'r', &set_key},
    {'l', &set_key},
    {'d', &set_key},
    {'t', &set_key},
    {'q', &set_key},
    {'p', &set_key},
    {'L', &set_level},
    {1001, &set_mapsize},
    {'w', &set_no_next},
    {'D', &set_debug}
};

static const struct option options[] = {
    {"help", no_argument, 0, 1000},
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'q'},
    {"key-pause", required_argument, NULL, 'p'},
    {"map-size", required_argument, NULL, 1001},
    {"without-next", no_argument, NULL, 'w'},
    {"debug", no_argument, NULL, 'D'},
    {NULL, no_argument, NULL, 0}
};

static void help(char **av)
{
    my_putstr("Usage: ", 1);
    my_putstr(av[0], 1);
    my_putstr(" [options]\nOptions:\n  --help Display this ", 1);
    my_putstr("help\n  -L --level={num} Start Tetris at level num (def: 1", 1);
    my_putstr(")\n  -l --key-left={K} Move the tetrimino LEFT using the K", 1);
    my_putstr(" key (def: left arrow)\n  -r --key-right={K} Move the tetr", 1);
    my_putstr("imino RIGHT using the K key (def: right arrow)\n  -t --key", 1);
    my_putstr("-turn={K} TURN the tetrimino clockwise 90d using the K key", 1);
    my_putstr(" (def: top arrow)\n  -d --key-drop={K} DROP the tetrimino ", 1);
    my_putstr("using the K key (def: down arrow)\n  -q --key-quit={K} QUI", 1);
    my_putstr("T the game using the K key (def: 'q' key)\n  -p --key-paus", 1);
    my_putstr("e={K} PAUSE/RESTART the game using the K key (def: space b", 1);
    my_putstr("ar)\n  --map-size={row,col} Set the numbers of rows and co", 1);
    my_putstr("lumns of the map (def: 20,10)\n  -w --without-next Hide ne", 1);
    my_putstr("xt tetrimino (def: false)\n  -D --debug Debug mode (def: f", 1);
    my_putstr("alse)\n", 1);
}

int run_param(tetris_t *tetris, int c)
{
    int check = 0;

    for (int i = 0; i < 10; i++)
        if (PARAM[i].c == c) {
            PARAM[i].fun(PARAM[i].c, optarg, tetris);
            check = 1;
            break;
        }
    return check;
}

static int parsing(int ac, char **av, tetris_t *tetris)
{
    int c;
    int check = 0;

    while ((c = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", options, NULL)) != -1) {
        if (c == 1000) {
            help(av);
            continue;
        }
        check = run_param(tetris, c);
        if (!check)
            return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    tetris_t tetris = {NULL, {{"^EOD", "^EOC", "^EOA", "^EOB",
    "Q", "(space)"}, "1", 1, "20*10", 0}};
    char buffer[10];

    if (parsing(ac, av, &tetris)) {
        my_putstr("Bad option\n", 2);
        help(av);
        return (84);
    }
    tetris.info = malloc(sizeof(int) * 3);
    if (tetris.debug_info.debug) {
        debug(&tetris);
        put_in_tab(&tetris);
    }
    my_putstr("Press any key to start Tetris\n", 1);
    read(0, buffer, 10);
    free(tetris.info);
    return (0);
}
