/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** set_zombes
*/

#include <my_defender.h>
#include <my_printf_tools.h>

bool pea_z1_collision(void *plant, z1_t *z1)
{
    pea_t *pea = ((pea_t *)plant);
    if (tow_box_touched(pea->pos, pea->rec, z1->pos, z1->rec)) {
        pea->life -= z1->att;
        return true;
    } else
        return false;
}

bool beet_z1_collision(void *plant, z1_t *z1)
{
    beet_t *beet = ((beet_t *)plant);

    if (tow_box_touched(beet->pos, beet->rec, z1->pos, z1->rec)) {
        beet->life -= z1->att;
        return true;
    } else
        return false;
}

bool flower_z1_collision(void *plant, z1_t *z1)
{
    sun_t *flower = ((sun_t *)plant);

    if (tow_box_touched(flower->pos, flower->rec, z1->pos, z1->rec)) {
        flower->life -= z1->att;
        return true;
    } else
        return false;
}

bool walnut_z1_collision(void *plant, z1_t *z1)
{
    walnut_t *walnut = ((walnut_t *)plant);

    if (tow_box_touched(walnut->pos, walnut->rec, z1->pos, z1->rec)) {
        walnut->exp += 50;
        walnut->life -= z1->att;
        return true;
    } else
        return false;
}

void check_colision_z1_plants(z1_t *z1, dlist_t **lst)
{
    int i, s = false;
    bool_fprt_t ptr[] = {
        {S_BEEF, beet_z1_collision},
        {S_SUN, flower_z1_collision},
        {S_PEA, pea_z1_collision},
        {S_WALNUT, walnut_z1_collision},
    };
    if ((*lst) != NULL)
        for (node_t *tmp = (*lst)->begin; tmp != NULL && s != true;
            tmp = tmp->next)
            s = ptr[set_fucon_bool(ptr, tmp->name)].ptr(tmp->data, z1);
    if (s == true)
        z1->speed.x = 0;
    else
        z1->speed.x = -7;
}