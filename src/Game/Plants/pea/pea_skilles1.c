/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** pea_skilles1
*/

#include <my_defender.h>

bool update_pea_exp(pea_t *pea, node_t *zombie, ball_t *ball)
{
    if (zombie->name == S_Z1 &&
        tow_box_touched(ball->pos, ball->rec, ((z1_t *)zombie->data)->pos,
                        ((z1_t *)zombie->data)->rec)) {
        ((z1_t *)zombie->data)->life -= pea->att;
        if (pea->level < 1000) pea->exp += 2;
        return true;
    } else if (zombie->name == S_Z2 &&
                tow_box_touched(ball->pos, ball->rec,
                                ((z2_t *)zombie->data)->pos,
                                ((z2_t *)zombie->data)->rec)) {
        ((z2_t *)zombie->data)->life -= pea->att;
        if (pea->level < 1000) pea->exp += 4;
        return true;
    }
    return false;
}

bool pea_ball_touched_zombies(ball_t *ball, dlist_t **l_z, pea_t *pea)
{
    if ((*l_z) != NULL)
        for (node_t *tmp = (*l_z)->begin; tmp != NULL; tmp = tmp->next) {
            if (update_pea_exp(pea, tmp, ball)) return true;
        }
    if (ball->pos.x < pea->pos.x + 55 + 400) return false;
    return true;
}

void draw_pea_ball(dlist_t **l_ball, pea_t *pea, data_t *src)
{
    if ((*l_ball) != NULL)
        for (node_t *tmp = (*l_ball)->begin; tmp != NULL; tmp = tmp->next) {
            pea_ball_animation(((ball_t *)tmp->data), pea->pos,
                                pea_ball_touched_zombies(((ball_t *)tmp->data),
                                                        &src->l_z, pea));
            sfRenderWindow_drawSprite(src->window, ((ball_t *)tmp->data)->sp,
                                        NULL);
        }
}