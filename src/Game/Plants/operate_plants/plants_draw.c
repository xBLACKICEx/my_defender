/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** plant_draw
*/

#include <my_defender.h>

void draw_pea(data_t *src, void *plant)
{
    pea_t *pea = ((pea_t *)plant);

    if (pea->life >= 0) {
        set_pea_ball_on_map(pea, src->textures);
        sfRenderWindow_drawSprite(src->window, pea->alive, NULL);
        draw_pea_ball(&pea->l_ball, pea, src);
    } else if (pea->life <= 0 && pea->in_death == 0) {
        pea->rec.left = 0;
        pea->in_death = 1;
    }
    if (pea->life <= 0 && pea->rec.left < 225)
        sfRenderWindow_drawSprite(src->window, pea->die, NULL);
    if (pea->rec.left == 225 && pea->in_death == 1)
        pea->in_death = 2;
    anim_pea(src->clock.clock1, pea);
}

void draw_beet(data_t *src, void *plant)
{
    beet_t *beet = ((beet_t *)plant);

    if (beet->life > 0) {
        set_beet_ball_on_map(beet, src->textures);
        sfRenderWindow_drawSprite(src->window, beet->alive, NULL);
        draw_beet_ball(&beet->l_ball, beet, src);
    } else if (beet->life <= 0 && beet->in_death == 0) {
        beet->rec.left = 0;
        beet->in_death = 1;
    }
    if (beet->life <= 0 && beet->rec.left < 165)
        sfRenderWindow_drawSprite(src->window, beet->die, NULL);
    if (beet->rec.left == 165 && beet->in_death == 1)
        beet->in_death = 2;
    anim_beet(src->clock.clock1, beet);
}

void draw_sun(data_t *src, void *plant)
{
    sun_t *sun = ((sun_t *)plant);

    if (sun->life > 0) {
        set_sunflower_on_map(sun, src->textures);
        sfRenderWindow_drawSprite(src->window, sun->alive, NULL);
        draw_sunflower_sun(&sun->l_sun, src->window);
    } else if (sun->life <= 0 && sun->in_death == 0) {
        sun->rec.left = 0;
        sun->in_death = 1;
    }
    if (sun->life <= 0 && sun->rec.left < 330)
        sfRenderWindow_drawSprite(src->window, sun->die, NULL);
    if (sun->rec.left == 330 && sun->in_death == 1)
        sun->in_death = 2;
    anim_sun(src->clock.clock1, sun);
}

void draw_walnut(data_t *src, void *plant)
{
    walnut_t *walnut = ((walnut_t *)plant);

    sfSprite_setTextureRect(walnut->alive, walnut->rec);
    if (walnut->life > 0) {
        set_walnut_leve(walnut, src->textures);
        sfRenderWindow_drawSprite(src->window, walnut->alive, NULL);
    } else if (walnut->life <= 0 && walnut->in_death == 0) {
        walnut->rec = (sfIntRect){0, 0, 66, 75};
        walnut->w_max = 264;
        walnut->rec.left = 0;
        walnut->in_death = 1;
    }
    if (walnut->life <= 0 && walnut->rec.left < 264)
        sfRenderWindow_drawSprite(src->window, walnut->die, NULL);
    if (walnut->rec.left == 264 && walnut->in_death == 1)
        walnut->in_death = 2;
    anim_walnut(src->clock.clock1, walnut);
}
