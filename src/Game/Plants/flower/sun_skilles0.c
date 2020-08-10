/*
** EPITECH PROJECT, 2020
** .my_defender (工作区)
** File description:
** sun_skilles
*/

#include <my_defender.h>

void anim_sun_sun(ball_t *sun_sun)
{
    sfTime time1 = sfClock_getElapsedTime(sun_sun->clock);
    float seconds = time1.microseconds / 1000000.0;

    if (seconds > 0.05) {
        move_rect(&sun_sun->rec, 50, 150);
        sun_sun->pos.y -= sun_sun->speed.y;
        sfSprite_setPosition(sun_sun->sp, sun_sun->pos);
        sfSprite_setTextureRect(sun_sun->sp, sun_sun->rec);
        sfClock_restart(sun_sun->clock);
    }
}

void creat_sun_flower_ball(dlist_t **l_sun, int size, plants_texture_t texture,
                            int time)
{
    if (((*l_sun) == NULL || (*l_sun)->len < size) && time == 5) {
        ball_t *sun = malloc(sizeof(ball_t));
        sun->sp = sfSprite_create();
        sun->clock = sfClock_create();
        sun->rec = (sfIntRect){0, 0, 50, 48};
        sun->pos = (sfVector2f){(rand() % 900 + 100), (rand() % 500 + 80)};
        sun->speed = (sfVector2f){0, 3};
        sfSprite_setTexture(sun->sp, texture.sun, true);
        sfSprite_setPosition(sun->sp, sun->pos);
        sfSprite_setTextureRect(sun->sp, sun->rec);
        push_back(l_sun, sun, 1);
    }
}

void set_flower_level(sun_t *sun)
{
    if (sun->seconds < 15) {
        sun->level = 1;
        sun->point = 25;
    } else if (sun->seconds >= 15 && sun->seconds <= 15 * 3) {
        sun->level = 2;
        sun->point = 50;
    } else {
        sun->level = 3;
        sun->point = 70;
    }
}

void set_sunflower_on_map(sun_t *sun, plants_texture_t texture)
{
    sfTime time = sfClock_getElapsedTime(sun->clock[1]);
    sfTime time2 = sfClock_getElapsedTime(sun->clock[2]);
    int t = sfTime_asSeconds(time2);

    sun->seconds = time.microseconds / 1000000;
    if (*sun->dropped) {
        if (sun->level == 1) creat_sun_flower_ball(&sun->l_sun, 2, texture, t);
        if (sun->level == 2) creat_sun_flower_ball(&sun->l_sun, 3, texture, t);
        if (sun->level == 3) creat_sun_flower_ball(&sun->l_sun, 4, texture, t);
    }
    set_flower_level(sun);
    if (t >= 5) sfClock_restart(sun->clock[2]);
}