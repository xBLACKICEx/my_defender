/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** csfml_tools3
*/

#include <my_defender.h>

void move_rect(sfIntRect *rect_pea, int offset, int max_value)
{
    rect_pea->left += offset;
    if (rect_pea->left >= max_value)
        rect_pea->left = 0;
}

void move_rect_deth(sfIntRect *rect_pea, int offset, int max_value)
{
    if (rect_pea->left < max_value)
        rect_pea->left += offset;
}