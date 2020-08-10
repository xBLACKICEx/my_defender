/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** creat_zombies
*/

#include <my_defender.h>

void z1_att_taime(z1_t *z1, dlist_t **l_plants)
{
    sfTime time = sfClock_getElapsedTime(z1->clock[1]);
    int t = sfTime_asSeconds(time);

    if (t == z1->interval) {
        check_colision_z1_plants(z1, l_plants);
        sfClock_restart(z1->clock[1]);
    }
}

void z2_att_taime(z2_t *z2, dlist_t **l_plants)
{
    sfTime time = sfClock_getElapsedTime(z2->clock[1]);
    int t = sfTime_asSeconds(time);

    if (t == z2->interval) {
        check_colision_z2_plants(z2, l_plants);
        sfClock_restart(z2->clock[1]);
    }
}

z1_t *creat_z1_node(int x, int y, plants_texture_t texture)
{
    z1_t *z1 = malloc(sizeof(z1_t));

    z1->alive = sfSprite_create();
    z1->die = sfSprite_create();
    creat_clock(z1->clock, 2);
    z1->pos  = (sfVector2f){15.0 * x, 15.0 * y};
    z1->speed = (sfVector2f){-7, 0};
    z1->rec = (sfIntRect){0, 0, 56, 90};
    sfSprite_setTexture(z1->die, texture.z1_die, sfTrue);
    sfSprite_setTexture(z1->alive, texture.z1_alive, sfTrue);
    sfSprite_setPosition(z1->alive, z1->pos);
    z1->att = 20;
    z1->level = 0;
    z1->life = 1000;
    z1->interval = 2;
    z1->in_death = 0;
    return z1;
}

z2_t *creat_z2_node(int x, int y, plants_texture_t texture)
{
    z2_t *z2 = malloc(sizeof(z2_t));

    z2->alive = sfSprite_create();
    z2->die = sfSprite_create();
    creat_clock(z2->clock, 2);
    z2->pos  = (sfVector2f){15.0 * x, 15.0 * y};
    z2->speed = (sfVector2f){-5, 0};
    z2->rec = (sfIntRect){0, 0, 75, 90};
    sfSprite_setTexture(z2->die, texture.z2_die, sfTrue);
    sfSprite_setTexture(z2->alive, texture.z2_alive, sfTrue);
    sfSprite_setPosition(z2->alive, z2->pos);
    z2->w_max = 150;
    z2->att = 40;
    z2->level = 0;
    z2->life = 1500;
    z2->interval = 2;
    z2->in_death = 0;
    return z2;
}

void creat_zombes_spwn(data_t *src, char *map)
{
    int x = 0, y = 0, end = 0;

    for (int i = 0; map[i] != '\0'; i++, x++) {
        if (map[i] == 'E') {
            end = x;
            y = 0;
        } else if (map[i] == '\n') {
            x = -1;
            y++;
        }
        if (map[i] == '1')
            push_back(&src->l_z,
                    creat_z1_node(x + end, y, src->textures), S_Z1);
        else if (map[i] == '2')
            push_back(&src->l_z,
                    creat_z2_node(x + end, y, src->textures), S_Z2);
    }
}