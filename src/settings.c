/*
** EPITECH PROJECT, 2019
** settings.c
** File description:
** settings.c
*/
#include "settings.h"
#include "my.h"

void set_key(int key, char *oarg, tetris_t* tetris)
{
    if (key == 'l')
        tetris->debug_info.keys[0] = !my_strcmp(oarg, " ") ? "(space)" : oarg;
    if (key == 'r')
        tetris->debug_info.keys[1] = !my_strcmp(oarg, " ") ? "(space)" : oarg;
    if (key == 't')
        tetris->debug_info.keys[2] = !my_strcmp(oarg, " ") ? "(space)" : oarg;
    if (key == 'd')
        tetris->debug_info.keys[3] = !my_strcmp(oarg, " ") ? "(space)" : oarg;
    if (key == 'q')
        tetris->debug_info.keys[4] = !my_strcmp(oarg, " ") ? "(space)" : oarg;
    if (key == 'p')
        tetris->debug_info.keys[5] = !my_strcmp(oarg, " ") ? "(space)" : oarg;
}

void set_level(int key, char *optarg, tetris_t *tetris)
{
    my_strcpy(tetris->debug_info.level, optarg);
}

void set_mapsize(int key, char *optarg, tetris_t *tetris)
{
    my_strcpy(tetris->debug_info.size, optarg);
}

void set_no_next(int key, char *optarg, tetris_t *tetris)
{
    tetris->debug_info.next = 0;
}

void set_debug(int key, char *optarg, tetris_t *tetris)
{
    tetris->debug_info.debug = 1;
}
