/*
** EPITECH PROJECT, 2018
** putstr
** File description:
** putstr
*/

#include "../../include/my.h"

void my_putstr(char *str, int channel)
{
    write(channel, str, my_strlen(str));
}
