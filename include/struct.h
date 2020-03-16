/*
** EPITECH PROJECT, 2019
** repository
** File description:
** epitech
*/

#ifndef MY_STRUCT_S
#define MY_STRUCT_S

typedef struct keys {
    char *keys[6];
    char *level;
    int next;
    char *size;
    int debug;
} keys_t;

typedef struct tetris_s {
    int *info;
    keys_t debug_info;
} tetris_t;

#endif

/*
info[0] x
info[0] y
info[0] color

*/
