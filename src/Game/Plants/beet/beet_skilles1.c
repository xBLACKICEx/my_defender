/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** beet_skilles1
*/

#include <my_defender.h>

bool update_beet_exp(beet_t *beet, node_t *zombie, ball_t *ball)
{
    if (zombie->name == S_Z1 &&
        tow_box_touched(ball->pos, ball->rec, ((z1_t *)zombie->data)->pos,
                        ((z1_t *)zombie->data)->rec)) {
        ((z1_t *)zombie->data)->life -= beet->att;
        if (beet->level < 600) beet->exp += 2;
        return true;
    } else if (zombie->name == S_Z2 &&
                tow_box_touched(ball->pos, ball->rec,
                                ((z2_t *)zombie->data)->pos,
                                ((z2_t *)zombie->data)->rec)) {
        ((z2_t *)zombie->data)->life -= beet->att;
        if (beet->level < 600) beet->exp += 4;
        return true;
    }
    return false;
}

bool beet_ball_touched_zombies(ball_t *ball, dlist_t **l_z, beet_t *beet)
{
    if ((*l_z) != NULL)
        for (node_t *tmp = (*l_z)->begin; tmp != NULL; tmp = tmp->next) {
            if (update_beet_exp(beet, tmp, ball)) return true;
        }
    if (ball->pos.x < beet->pos.x + 55 + 400) return false;
    return true;
}

void draw_beet_ball(dlist_t **l_ball, beet_t *beet, data_t *src)
{
    if ((*l_ball) != NULL)
        for (node_t *tmp = (*l_ball)->begin; tmp != NULL; tmp = tmp->next) {
            beet_ball_animation(((ball_t *)tmp->data), beet->pos,
                                beet_ball_touched_zombies(((ball_t *)tmp->data),
                                                        &src->l_z, beet));
            sfRenderWindow_drawSprite(src->window, ((ball_t *)tmp->data)->sp,
                                        NULL);
        }
}