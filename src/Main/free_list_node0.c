/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_map_data
*/

#include <my_defender.h>

void free_pea_node(void *data)
{
    pea_t *pea = ((pea_t *)data);

    *pea->dropped = false;
    clear_dlist(&pea->l_ball, free_sun_sun_node);
    sfClock_destroy(pea->clock);
    sfSprite_destroy(pea->alive);
    sfSprite_destroy(pea->die);
    free(pea);
}

void free_beet_node(void *data)
{
    beet_t *beet = ((beet_t *)data);

    *beet->dropped = false;
    clear_dlist(&beet->l_ball, free_sun_sun_node);
    sfClock_destroy(beet->clock);
    sfSprite_destroy(beet->alive);
    sfSprite_destroy(beet->die);
    free(beet);
}

void free_sun_node(void *data)
{
    sun_t *sun = ((sun_t *)data);

    *sun->dropped = false;
    clear_dlist(&sun->l_sun, free_sun_sun_node);
    free_clock(sun->clock, 3);
    sfSprite_destroy(sun->alive);
    sfSprite_destroy(sun->die);
    free(sun);
}

void free_walnut_node(void *data)
{
    walnut_t *walnut = ((walnut_t *)data);

    *walnut->dropped = false;
    sfClock_destroy(walnut->clock);
    sfSprite_destroy(walnut->alive);
    sfSprite_destroy(walnut->die);
    free(walnut);
}