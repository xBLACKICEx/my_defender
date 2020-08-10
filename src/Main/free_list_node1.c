/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_map_data
*/

#include <my_defender.h>

void free_sun_sun_node(node_t *node)
{
    sfClock_destroy(((ball_t *)node->data)->clock);
    sfSprite_destroy(((ball_t *)node->data)->sp);
    free(node->data);
    free(node);
}

void free_z1_node(void *data)
{
    free_clock(((z1_t *)data)->clock, 2);
    sfSprite_destroy(((z1_t *)data)->alive);
    sfSprite_destroy(((z1_t *)data)->die);
    free(((z1_t *)data));
}

void free_z2_node(void *data)
{
    free_clock(((z2_t *)data)->clock, 2);
    sfSprite_destroy(((z2_t *)data)->alive);
    sfSprite_destroy(((z2_t *)data)->die);
    free(((z2_t *)data));
}

void free_mini_map_node(void *data)
{
    sfSprite_destroy(((mini_map_t *)data)->sp);
    free(((mini_map_t *)data));
}