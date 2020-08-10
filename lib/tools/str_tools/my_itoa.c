/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_itoa
*/

#include <my_tools.h>
#include <stddef.h>

char *my_itoa(int nbr)
{
    unsigned int i = 1u;
    char *n = NULL, s;

    if (nbr < 0) {
        nbr *= -1;
        n = my_strncdup(n, "-", 1);
    }
    for (int tmp = nbr; (tmp /= 10) != 0; i *= 10);
    for (; i != 0;  i /= 10) {
        s = (nbr / i % 10) + 48;
        n = my_strncdup(n, &s, 1);
    }
    return n;
}