/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** creat_plants
*/

#include <my_defender.h>
#include <my_tools.h>
#include <my_printf_tools.h>

void creat_plants_list(data_t *src)
{
    sfIntRect rec;
    void (*ptr[])() = {creat_plants_walnut, creat_plants_sun, creat_plants_pea,
                        creat_plants_beet};

    for (node_t *tmp = src->lst_map->begin; tmp != NULL; tmp = tmp->next) {
        rec = sfSprite_getTextureRect(((mini_map_t *)tmp->data)->sp);
        if (button_clicked(src->event, src->mouse.pos,
                            ((mini_map_t *)tmp->data)->pos, rec) &&
            src->selected_plant.sp != NULL &&
            ((mini_map_t *)tmp->data)->dropped == false) {
            ptr[src->selected_plant.name](src, (mini_map_t *)tmp->data);
            sfSprite_destroy(src->selected_plant.sp);
            *src->selected_plant.dropped = false;
            src->selected_plant.sp = NULL;
        }
    }
}

STRUCT_NAME_t set_fucon(fprt_t *fptr, STRUCT_NAME_t name)
{
    unsigned char i = 0;

    for (; fptr[i].ptr != NULL && fptr[i].name != name; i++);
    if (fptr[i].ptr == NULL)
        pstr_c("fptr[i].ptr == NULL, dont have this name !!!\n");
    return i;
}

bool plants_and_zombies_dath(node_t *node, void *data)
{
    if (node->name == S_PEA && ((pea_t *)node->data)->in_death == 2)
        return true;
    if (node->name == S_BEEF && ((beet_t *)node->data)->in_death == 2)
        return true;
    if (node->name == S_SUN && ((sun_t *)node->data)->in_death == 2)
        return true;
    if (node->name == S_WALNUT && ((walnut_t *)node->data)->in_death == 2)
        return true;
    if (node->name == S_Z1 && ((z1_t *)node->data)->in_death == 2) return true;
    if (node->name == S_Z2 && ((z2_t *)node->data)->in_death == 2) return true;
    if (node->name == S_Z1 && ((z1_t *)node->data)->pos.x <= 200) {
        ((data_t *)data)->life -= 1;
        return true;
    } else if (node->name == S_Z2 && ((z2_t *)node->data)->pos.x <= 200) {
        ((data_t *)data)->life -= 1;
        return true;
    }
    return false;
}

void plants_lst_draw(data_t *src)
{
    fprt_t fptr[] = {{S_WALNUT, draw_walnut},
                    {S_SUN, draw_sun},
                    {S_PEA, draw_pea},
                    {S_BEEF, draw_beet},
                    {0, NULL}};
    if (src->win_page == GAME_PAGE && src->lst != NULL &&
        !src->game.menu.cliked)
        for (node_t *tmp = src->lst->begin; tmp != NULL; tmp = tmp->next)
            fptr[set_fucon(fptr, tmp->name)].ptr(src, tmp->data);
    pop_list(&src->lst, NULL, plants_and_zombies_dath, free_node);
    if (src->win_page == GAME_PAGE)
        for (int i = 0; i < src->life; i++)
            sfRenderWindow_drawSprite(src->window, src->game.life[i].sp, NULL);
}

void zombies_lst_draw(data_t *src)
{
    fprt_t fptr[] = {{S_Z1, draw_z1}, {S_Z2, draw_z2}};
    if (src->win_page == GAME_PAGE && src->l_z != NULL &&
        !src->game.menu.cliked)
        for (node_t *tmp = src->l_z->begin; tmp != NULL; tmp = tmp->next)
            fptr[set_fucon(fptr, tmp->name)].ptr(src, tmp->data);
    pop_list(&src->l_z, src, plants_and_zombies_dath, free_node);
    if (src->win_page == GAME_PAGE) {
        set_round_1(src);
        set_round_2(src);
        set_round_3(src);
    }
}