/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** pea_skilles0
*/

#include <my_defender.h>

void creat_pea_ball(dlist_t **l_ball, int leve, plants_texture_t texture,
                    sfVector2f pos)
{
    if ((*l_ball) == NULL || (*l_ball)->len < leve) {
        ball_t *ball = malloc(sizeof(ball_t));
        set_sprite(&ball->sp, &texture.ball);
        ball->pos.x = pos.x + 55;
        ball->pos.y = pos.y + 15;
        ball->clock = sfClock_create();
        ball->speed = (sfVector2f){5, 0};
        ball->rec = (sfIntRect){0, 0, 20, 20};
        sfSprite_setPosition(ball->sp, ball->pos);
        sfSprite_setTextureRect(ball->sp, ball->rec);
        push_back(l_ball, ball, 2);
    }
    if ((*l_ball)->len < leve) creat_pea_ball(l_ball, leve, texture, pos);
}

void set_pea_leve(pea_t *pea, plants_texture_t texture)
{
    if (pea->level == 1 && pea->exp >= 300) {
        sfSprite_destroy(pea->alive);
        set_sprite(&pea->alive, &texture.pea_a2);
        pea->level = 2;
        pea->att = 20;
    } else if (pea->level == 2 && pea->exp >= 1000) {
        sfSprite_destroy(pea->alive);
        set_sprite(&pea->alive, &texture.pea_a3);
        pea->level = 3;
        pea->att = 25;
    }
    sfSprite_setPosition(pea->alive, pea->pos);
}

void set_pea_ball_on_map(pea_t *pea, plants_texture_t texture)
{
    if (*pea->dropped) {
        if (pea->level == 1) creat_pea_ball(&pea->l_ball, 1, texture, pea->pos);
        if (pea->level == 3) creat_pea_ball(&pea->l_ball, 3, texture, pea->pos);
    }
    set_pea_leve(pea, texture);
}

void pea_ball_animation(ball_t *ball, sfVector2f pea_pos, bool s)
{
    sfTime time1 = sfClock_getElapsedTime(ball->clock);
    float seconds = time1.microseconds / 1000000.0;

    if (seconds > 0.05) {
        if (s == false)
            ball->pos.x += ball->speed.x;
        else if (s == true)
            ball->pos.x = pea_pos.x + 55;
        sfSprite_setPosition(ball->sp, ball->pos);
        sfClock_restart(ball->clock);
    }
}