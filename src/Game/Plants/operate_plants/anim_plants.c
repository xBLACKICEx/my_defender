/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** creat_plants
*/

#include <my_defender.h>

void anim_pea(sfClock *clock, pea_t *pea)
{
    sfTime time = sfClock_getElapsedTime(pea->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.1) {
        if (pea->life > 0) {
            move_rect(&pea->rec, 75, 150);
            sfSprite_setTextureRect(pea->alive, pea->rec);
        } else if (pea->life <= 0 && pea->rec.left < 225) {
            move_rect_deth(&pea->rec, 75, 225);
            sfSprite_setTextureRect(pea->die, pea->rec);
        }
        sfClock_restart(pea->clock);
    }
}

void anim_beet(sfClock *clock, beet_t *beet)
{
    sfTime time = sfClock_getElapsedTime(beet->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.2) {
        if (beet->life > 0) {
            move_rect(&beet->rec, beet->rec.width, beet->w_max);
            sfSprite_setTextureRect(beet->alive, beet->rec);
        } else if (beet->life <= 0 && beet->rec.left < 165) {
            move_rect_deth(&beet->rec, 55, 225);
            sfSprite_setTextureRect(beet->die, beet->rec);
        }
        sfClock_restart(beet->clock);
    }
}

void anim_sun(sfClock *clock, sun_t *sun)
{
    sfTime time = sfClock_getElapsedTime(sun->clock[0]);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.3) {
        if (sun->life > 0) {
            move_rect(&sun->rec, 66, 132);
            sfSprite_setTextureRect(sun->alive, sun->rec);
        } else if (sun->life <= 0 && sun->rec.left < 330) {
            move_rect_deth(&sun->rec, 66, 330);
            sfSprite_setTextureRect(sun->die, sun->rec);
        }
        sfClock_restart(sun->clock[0]);
    }
}

void anim_walnut(sfClock *clock, walnut_t *walnut)
{
    sfTime time = sfClock_getElapsedTime(walnut->clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.3) {
        if (walnut->life > 0) {
            move_rect(&walnut->rec, walnut->rec.width, walnut->w_max);
            sfSprite_setTextureRect(walnut->alive, walnut->rec);
        } else if (walnut->life <= 0 && walnut->rec.left < 264) {
            move_rect_deth(&walnut->rec, 66, 264);
            sfSprite_setTextureRect(walnut->die, walnut->rec);
        }
        sfClock_restart(walnut->clock);
    }
}