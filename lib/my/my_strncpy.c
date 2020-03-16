/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** copy str
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    while (i != n){
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
