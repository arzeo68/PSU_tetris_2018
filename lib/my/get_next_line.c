/*
** EPITECH PROJECT, 2019
** EPITECH
** File description:
** gnl
*/

#include <stdlib.h>
#include <zconf.h>
#include <fcntl.h>
#include "../../include/get_next_line.h"

char *new_str(const char *str, int i)
{
    char *end;
    int j;
    int k;

    for (k = 0; str[i + k]; k++);
    if (!(end = malloc(k + 2)))
        return (NULL);
    for (j = 0; str[i]; i++, j++)
        end[j] = str[i];
    end[j] = '\0';
    return (end);
}

char *my_realloc(char *str, char *buffer, int size)
{
    char *nstr;
    int i = 0;

    buffer[size] = '\0';
    if (str != NULL)
        for (; str[i]; i++);
    if (!(nstr = malloc(i + READ_SIZE + 1)))
        return (NULL);
    if (str != NULL)
        for (int j = 0; str[j]; j++)
            nstr[j] = str[j];
    for (int j = 0; buffer[j]; j++, i++)
        nstr[i] = buffer[j];
    nstr[i] = '\0';
    free(str);
    return (nstr);
}

char *read_line(int fd, char *buffer, char *str)
{
    int size;

    if (!(size = read(fd, buffer, READ_SIZE)))
        return NULL;
    if ((str = my_realloc(str, buffer, size)) == NULL)
        return (NULL);
    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == '\n')
            return (str);
    read_line(fd, buffer, str);
    return NULL;
}

char *get_next_line(int fd)
{
    char *buffer = malloc((READ_SIZE + 1));
    static char *str = NULL;
    char *res;
    int i = 0;
    int a;

    if (fd < 0 || READ_SIZE == 0 || !buffer)
        return (NULL);
    str = read_line(fd, buffer, str);
    if (str == NULL || str[i] == '\0')
        return (NULL);
    for (a = 0; str[a] != '\n' && str[a]; a++);
    if (!(res = malloc(a + 1)))
        return (NULL);
    for (i = 0; str[i] != '\n' && str[i]; i++)
        res[i] = str[i];
    res[i] = '\0';
    str = new_str(str, i + 1);
    free(buffer);
    return (res);
}
