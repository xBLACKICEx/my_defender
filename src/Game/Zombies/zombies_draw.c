/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** zombie_draw
*/

#include <my_defender.h>

void anim_z1(sfClock *clock, z1_t *z1)
{
    sfTime time1 = sfClock_getElapsedTime(z1->clock[0]);
    float seconds = time1.microseconds / 1000000.0;

    if (seconds > 0.18) {
        if (z1->life > 0) {
            move_rect(&z1->rec, 56, 112);
            sfSprite_setTextureRect(z1->alive, z1->rec);
        } else if (z1->life <= 0 && z1->in_death == 1) {
            move_rect_deth(&z1->rec, 56, 336);
            sfSprite_setTextureRect(z1->die, z1->rec);
        }
        z1->pos.x += z1->speed.x;
        sfClock_restart(z1->clock[0]);
    }
}

void anim_z2(sfClock *clock, z2_t *z2)
{
    sfTime time1 = sfClock_getElapsedTime(z2->clock[0]);
    float seconds = time1.microseconds / 1000000.0;

    if (seconds > 0.18) {
        if (z2->life > 0) {
            move_rect(&z2->rec, z2->rec.width, z2->w_max);
            sfSprite_setTextureRect(z2->alive, z2->rec);
        } else if (z2->life <= 0 && z2->in_death == 1) {
            move_rect_deth(&z2->rec, z2->rec.width, z2->w_max);
            sfSprite_setTextureRect(z2->die, z2->rec);
        }
        z2->pos.x += z2->speed.x;
        sfClock_restart(z2->clock[0]);
    }
}

void draw_z1(data_t *src, void *zombie)
{
    z1_t *z1 = ((z1_t *)zombie);

    z1_att_taime(z1, &src->lst);
    if (z1->life > 0) {
        sfSprite_setPosition(z1->alive, z1->pos);
        sfRenderWindow_drawSprite(src->window, z1->alive, NULL);
    } else if (z1->life <= 0 && z1->in_death == 0) {
        z1->rec.left = 0;
        z1->in_death = 1;
        sfSprite_setTextureRect(z1->die, z1->rec);
    }
    if (z1->life <= 0 && z1->rec.left < 336)
        sfRenderWindow_drawSprite(src->window, z1->die, NULL);
    if (z1->rec.left == 336 && z1->in_death == 1)
        z1->in_death = 2;
    sfSprite_setPosition(z1->die, z1->pos);
    anim_z1(src->clock.clock1, z1);
}

void draw_z2(data_t *src, void *zombie)
{
    z2_t *z2 = ((z2_t *)zombie);

    z2_att_taime(z2, &src->lst);
    if (z2->life > 0) {
        sfSprite_setPosition(z2->alive, z2->pos);
        sfRenderWindow_drawSprite(src->window, z2->alive, NULL);
    } else if (z2->life <= 0 && z2->in_death == 0) {
        z2->rec.left = 0;
        z2->rec = (sfIntRect){0, 0, 77, 90};
        z2->w_max = 462;
        z2->in_death = 1;
        sfSprite_setTextureRect(z2->die, z2->rec);
    }
    if (z2->life <= 0 && z2->rec.left < 462)
        sfRenderWindow_drawSprite(src->window, z2->die, NULL);
    if (z2->rec.left == 462 && z2->in_death == 1)
        z2->in_death = 2;
    sfSprite_setPosition(z2->die, z2->pos);
    anim_z2(src->clock.clock1, z2);
}