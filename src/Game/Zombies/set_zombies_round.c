/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** set_game_round
*/

#include <my_tools.h>
#include <my_defender.h>

void display_round(data_t *src)
{
    char *tmp;

    if (!src->clock.clock1) src->clock.clock1 = sfClock_create();
    src->clock.time = sfClock_getElapsedTime(src->clock.clock1);
    src->r = my_strncdup(src->r, "Round :", 8);
    tmp = my_itoa(src->round + 1);
    src->r = my_strncdup(src->r, tmp, my_strlen(tmp));
    sfText_setString(src->t_round.buf, src->r);
    sfRenderWindow_drawText(src->window, src->t_round.buf, NULL);
    if (src->r != NULL) free(src->r);
    src->r = NULL;
    if (tmp) free(tmp);
    tmp = NULL;
}

void set_round_1(data_t *src)
{
    if (src->l_z == NULL && src->round == 0) {
        display_round(src);
        if (sfTime_asSeconds(src->clock.time) >= 3.0) {
            open_map(src, ZOMBIES_SPAWN1, creat_zombes_spwn);
            sfClock_destroy(src->clock.clock1);
            src->clock.clock1 = NULL;
            src->round = 1;
        }
    }
}

void set_round_2(data_t *src)
{
    if (src->l_z == NULL && src->round == 1) {
        display_round(src);
        if (sfTime_asSeconds(src->clock.time) >= 3.0) {
            open_map(src, ZOMBIES_SPAWN2, creat_zombes_spwn);
            sfClock_destroy(src->clock.clock1);
            src->clock.clock1 = NULL;
            src->round = 2;
        }
    }
}

void set_round_3(data_t *src)
{
    if (src->l_z == NULL && src->round == 2) {
        display_round(src);
        if (sfTime_asSeconds(src->clock.time) >= 3.0) {
            open_map(src, ZOMBIES_SPAWN3, creat_zombes_spwn);
            sfClock_destroy(src->clock.clock1);
            src->clock.clock1 = NULL;
            src->round = 3;
        }
    }
}