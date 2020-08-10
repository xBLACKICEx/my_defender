/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** walnut_skiles0
*/

#include <my_defender.h>

void set_walnut_leve(walnut_t *walnut, plants_texture_t texture)
{
    if (walnut->level == 1 && walnut->exp >= 250) {
        sfSprite_destroy(walnut->alive);
        set_sprite(&walnut->alive, &texture.walnut_a2);
        walnut->w_max = 159;
        walnut->rec = (sfIntRect){0, 0, 53, 78};
        walnut->life = 150;
        walnut->level = 2;
    }
    sfSprite_setPosition(walnut->alive, walnut->pos);
    sfSprite_setTextureRect(walnut->alive, walnut->rec);
}