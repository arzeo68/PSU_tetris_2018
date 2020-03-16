/*
** EPITECH PROJECT, 2019
** settings.h
** File description:
** settings.h
*/
#ifndef TETRIS_SETTINGS_H
    #define TETRIS_SETTINGS_H

#include "struct.h"

typedef struct param {
    int c;
    void (*fun)(int, char *, tetris_t *);
} param_t;

void set_key(int key, char *oarg, tetris_t* tetris);
void set_level(int key, char *optarg, tetris_t *tetris);
void set_mapsize(int key, char *optarg, tetris_t *tetris);
void set_no_next(int key, char *optarg, tetris_t *tetris);
void set_debug(int key, char *optarg, tetris_t *tetris);

#endif //TETRIS_SETTINGS_H
