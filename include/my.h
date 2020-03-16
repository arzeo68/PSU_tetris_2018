/*
** EPITECH PROJECT, 2019
** EPITECH
** File description:
** [enter description here]
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include <stdio.h>
#include "struct.h"

#define ABS(X) X = X < 0 ? X * -1 : X

int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char *str);
int my_isneg(int nb);
int my_is_prime(int nb);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char *str, int channel);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *end, char *first);
int my_strcmp(char const *s1, char const *s2);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char dest, char const *src, int nb);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **str_to_tab(char *str, char separator);
char *my_itoa(int n);
void itoa_isnegative(int *n, int *negative);
int my_getnbr_char(char c);
char *my_str_dup(char *str);

/*check_file*/

int check_file(char *str, tetris_t *tet);
int alphabetical_order(tetris_t tetris);
void put_in_tab(tetris_t *tetris);
void debug(tetris_t *tetris);
int my_strlen_custom(char *str);
char *find_name(char *str);
int print_info(char **file, int status, tetris_t *tet, char *str);
int check_lengh(char *str);
int check_tetrimino(tetris_t *tet, char **shape);
int put_in_struct(tetris_t *tet, char *str);
#endif

/*
#ifdef DEBUG
    printf("ta grosse daronne\n");
#endif
*/