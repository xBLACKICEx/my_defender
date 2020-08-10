/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** plants_data
*/

#include <my_defender.h>

void creat_plants_pea(data_t *src, mini_map_t *mini_map)
{
    pea_t *peashooter = malloc(sizeof(pea_t));

    peashooter->exp = 0;
    peashooter->att = 10;
    peashooter->level = 1;
    peashooter->life = 40;
    peashooter->in_death = 0;
    peashooter->l_ball = NULL;
    peashooter->dropped = &mini_map->dropped;
    *peashooter->dropped = true;
    peashooter->pos = mini_map->pos;
    peashooter->rec = (sfIntRect){75, 0, 75, 75};
    peashooter->clock = sfClock_create();
    set_sprite(&peashooter->die, &src->textures.pea_die);
    set_sprite(&peashooter->alive, &src->textures.pea_a1);
    sfSprite_setPosition(peashooter->die, mini_map->pos);
    sfSprite_setPosition(peashooter->alive, mini_map->pos);
    sfSprite_setTextureRect(peashooter->alive, peashooter->rec);
    sfSprite_setTextureRect(peashooter->die, peashooter->rec);
    push_back(&src->lst, peashooter, S_PEA);
}

void creat_plants_sun(data_t *src, mini_map_t *mini_map)
{
    sun_t *sunflower = malloc(sizeof(sun_t));

    sunflower->level = 1;
    sunflower->life = 40;
    sunflower->seconds = 0;
    sunflower->l_sun = NULL;
    sunflower->in_death = 0;
    sunflower->dropped = &mini_map->dropped;
    *sunflower->dropped = true;
    sunflower->pos = mini_map->pos;
    sunflower->rec = (sfIntRect){0, 0, 66, 75};
    creat_clock(sunflower->clock, 3);
    set_sprite(&sunflower->alive, &src->textures.flower_alive);
    set_sprite(&sunflower->die, &src->textures.flower_die);
    sfSprite_setPosition(sunflower->die, mini_map->pos);
    sfSprite_setPosition(sunflower->alive, mini_map->pos);
    sfSprite_setTextureRect(sunflower->alive, sunflower->rec);
    sfSprite_setTextureRect(sunflower->die, sunflower->rec);
    push_back(&src->lst, sunflower, S_SUN);
}

void creat_plants_beet(data_t *src, mini_map_t *mini_map)
{
    beet_t *beet = malloc(sizeof(beet_t));

    beet->exp = 0;
    beet->att = 25;
    beet->level = 1;
    beet->life = 40;
    beet->w_max = 110;
    beet->in_death = 0;
    beet->l_ball = NULL;
    beet->dropped = &mini_map->dropped;
    *beet->dropped = true;
    beet->pos = mini_map->pos;
    beet->rec = (sfIntRect){0, 0, 55, 75};
    beet->clock = sfClock_create();
    set_sprite(&beet->die, &src->textures.beet_die);
    set_sprite(&beet->alive, &src->textures.beet_a1);
    sfSprite_setPosition(beet->die, mini_map->pos);
    sfSprite_setPosition(beet->alive, mini_map->pos);
    sfSprite_setTextureRect(beet->die, beet->rec);
    push_back(&src->lst, beet, S_BEEF);
}

void creat_plants_walnut(data_t *src, mini_map_t *mini_map)
{
    walnut_t *walnut = malloc(sizeof(walnut_t));

    walnut->exp = 0;
    walnut->level = 1;
    walnut->life = 100;
    walnut->w_max = 264;
    walnut->in_death = 0;
    walnut->dropped = &mini_map->dropped;
    *walnut->dropped = true;
    walnut->pos = mini_map->pos;
    walnut->rec = (sfIntRect){0, 0, 66, 75};
    walnut->clock = sfClock_create();
    set_sprite(&walnut->die, &src->textures.walnut_die);
    set_sprite(&walnut->alive, &src->textures.walnut_a1);
    sfSprite_setPosition(walnut->die, mini_map->pos);
    sfSprite_setPosition(walnut->alive, mini_map->pos);
    sfSprite_setTextureRect(walnut->alive, walnut->rec);
    sfSprite_setTextureRect(walnut->die, walnut->rec);
    push_back(&src->lst, walnut, S_WALNUT);
}