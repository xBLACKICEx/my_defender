/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** zombies_skilles1
*/


#include <my_defender.h>
#include <my_printf_tools.h>

bool pea_z2_collision(void *plant, z2_t *z2)
{
    pea_t *pea = ((pea_t *)plant);
    if (tow_box_touched(pea->pos, pea->rec, z2->pos, z2->rec)) {
        pea->life -= z2->att;
        return true;
    } else
        return false;
}

bool beet_z2_collision(void *plant, z2_t *z2)
{
    beet_t *beet = ((beet_t *)plant);

    if (tow_box_touched(beet->pos, beet->rec, z2->pos, z2->rec)) {
        beet->life -= z2->att;
        return true;
    } else
        return false;
}

bool flower_z2_collision(void *plant, z2_t *z2)
{
    sun_t *flower = ((sun_t *)plant);

    if (tow_box_touched(flower->pos, flower->rec, z2->pos, z2->rec)) {
        flower->life -= z2->att;
        return true;
    } else
        return false;
}

bool walnut_z2_collision(void *plant, z2_t *z2)
{
    walnut_t *walnut = ((walnut_t *)plant);

    if (tow_box_touched(walnut->pos, walnut->rec, z2->pos, z2->rec)) {
        walnut->exp += 50;
        walnut->life -= z2->att;
        return true;
    } else
        return false;
}

void check_colision_z2_plants(z2_t *z2, dlist_t **lst)
{
    int i, s = false;
    bool_fprt_t ptr[] = {
        {S_BEEF, beet_z2_collision},
        {S_SUN, flower_z2_collision},
        {S_PEA, pea_z2_collision},
        {S_WALNUT, walnut_z2_collision},
    };
    if ((*lst) != NULL)
        for (node_t *tmp = (*lst)->begin; tmp != NULL && s != true;
            tmp = tmp->next)
            s = ptr[set_fucon_bool(ptr, tmp->name)].ptr(tmp->data, z2);
    if (s == true)
        z2->speed.x = 0;
    else
        z2->speed.x = -5;
}