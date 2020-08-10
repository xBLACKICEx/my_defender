/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** pea_skilles0
*/

#include <my_defender.h>

void creat_beet_ball(dlist_t **l_ball, int leve, plants_texture_t texture,
                    sfVector2f pos)
{
    if ((*l_ball) == NULL || (*l_ball)->len < leve) {
        ball_t *ball = malloc(sizeof(ball_t));
        set_sprite(&ball->sp, &texture.bullet);
        ball->pos.x = pos.x + 55;
        ball->pos.y = pos.y + 40;
        ball->clock = sfClock_create();
        ball->speed = (sfVector2f){5, 0};
        ball->rec = (sfIntRect){0, 0, 28, 18};
        sfSprite_setPosition(ball->sp, ball->pos);
        sfSprite_setTextureRect(ball->sp, ball->rec);
        push_back(l_ball, ball, 2);
    }
    if ((*l_ball)->len < leve) creat_beet_ball(l_ball, leve, texture, pos);
}

void set_beet_leve(beet_t *beet, plants_texture_t texture)
{
    if (beet->level == 1 && beet->exp >= 50) {
        sfSprite_destroy(beet->alive);
        set_sprite(&beet->alive, &texture.beet_a2);
        beet->rec = (sfIntRect){0, 0, 61, 86};
        beet->w_max = 122;
        beet->level = 2;
        beet->att = 30;
    }
    sfSprite_setPosition(beet->alive, beet->pos);
    sfSprite_setTextureRect(beet->alive, beet->rec);
}

void set_beet_ball_on_map(beet_t *beet, plants_texture_t texture)
{
    if (*beet->dropped) {
        if (beet->level == 1)
            creat_beet_ball(&beet->l_ball, 1, texture, beet->pos);
        if (beet->level == 3)
            creat_beet_ball(&beet->l_ball, 3, texture, beet->pos);
    }
    set_beet_leve(beet, texture);
}

void beet_ball_animation(ball_t *ball, sfVector2f beet_pos, bool s)
{
    sfTime time1 = sfClock_getElapsedTime(ball->clock);
    float seconds = time1.microseconds / 1000000.0;

    if (seconds > 0.05) {
        if (s == false)
            ball->pos.x += ball->speed.x;
        else if (s == true)
            ball->pos.x = beet_pos.x + 55;
        sfSprite_setPosition(ball->sp, ball->pos);
        sfClock_restart(ball->clock);
    }
}
