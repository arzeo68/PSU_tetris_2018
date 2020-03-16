/*
** EPITECH PROJECT, 2019
** Repository
** File description:
** [enter description here]
*/

#include "../../include/my.h"

void itoa_isnegative(int *n, int *negative)
{
    if (*n < 0) {
        *n *= -1;
        *negative = 1;
    }
}

char *my_itoa(int n)
{
    int tmpn;
    int len;
    int negative;
    char *str;

    tmpn = n;
    len = 2;
    negative = 0;
    itoa_isnegative(&n, &negative);
    while (tmpn /= 10)
        len++;
    len += negative;
    if ((str = malloc(sizeof(char) * len)) == NULL)
        return (NULL);
    str[--len] = '\0';
    while (len--) {
        str[len] = n % 10 + '0';
        n = n / 10;
    }
    return (str);
}
