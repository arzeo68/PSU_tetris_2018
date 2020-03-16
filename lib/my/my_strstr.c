/*
** EPITECH PROJECT, 2018
** strst
** File description:
** strstr
*/

char *my_strstr(char *str, char *to_find)
{
    int	i = 0;
    int	j = 0;

    while (str[i] != '\0') {
        if (str[i] != to_find[j])
            j = 0;
        else
            j = j + 1;
        if (!to_find[j]) {
            i = i - (j - 1);
            return (str + i);
        }
        i = i + 1;
    }
    return (0);
}
