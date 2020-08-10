/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** sun_skilles1
*/

#include <my_defender.h>

void cheak_click_sun_sun(dlist_t **l_sun, data_t *src, unsigned int point)
{
    if ((*l_sun))
        for (node_t *tmp = (*l_sun)->begin; tmp != NULL; tmp = tmp->next)
            if (button_clicked(src->event, src->mouse.pos,
                                ((ball_t *)tmp->data)->pos,
                                ((ball_t *)tmp->data)->rec)) {
                src->score.points += point;
                pop_center(l_sun, tmp, free_sun_sun_node);
                cheak_click_sun_sun(l_sun, src, point);
                return;
            }
}

void loop_sun_t_struct(data_t *src, void (*fon)())
{
    if (src->lst != NULL)
        for (node_t *tmp1 = src->lst->begin; tmp1 != NULL; tmp1 = tmp1->next)
            if (tmp1->name == S_SUN && ((sun_t *)tmp1->data)->l_sun != NULL)
                fon(&((sun_t *)tmp1->data)->l_sun, src,
                    ((sun_t *)tmp1->data)->point);
}

bool cheak_sun_out_of_map(node_t *node, void *data)
{
    if (((ball_t *)node->data)->pos.y <= -50) return true;
    return false;
}

void draw_sunflower_sun(dlist_t **l_sun, sfRenderWindow *win)
{
    pop_list(l_sun, NULL, cheak_sun_out_of_map, free_sun_sun_node);
    if ((*l_sun) != NULL)
        for (node_t *tmp = (*l_sun)->begin; tmp != NULL; tmp = tmp->next) {
            anim_sun_sun(((ball_t *)tmp->data));
            sfRenderWindow_drawSprite(win, ((ball_t *)tmp->data)->sp, NULL);
        }
}