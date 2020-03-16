/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
**  nombre
*/

#include "../../include/my.h"

void my_put_nbr(int nb)
{
    int debut;
    int fin;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    else {
        fin = nb % 10;
        debut = nb / 10;
        if (debut != 0)
            my_put_nbr(debut);
        my_putchar(fin + '0');
    }
}
