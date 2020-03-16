/*
** EPITECH PROJECT, 2018
** ncmp
** File description:
** ncmp
*/

int my_strncmp(char const *s1, char const *s2, int nb)
{
    for (int i = 0; i < nb && s1[i] && s2[i]; i++) {
        if (s1[i] > s2[i])
            return (1);
        else if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
}
