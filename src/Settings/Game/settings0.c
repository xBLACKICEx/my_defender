/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** settings0
*/

#include <my_defender.h>

bool clean_list_plants(node_t *node, void *data)
{
    if (node->name == S_PEA)
        *((pea_t *)node->data)->dropped = false;
    if (node->name == S_SUN)
        *((sun_t *)node->data)->dropped = false;
    if (node->name == S_BEEF)
        *((beet_t *)node->data)->dropped = false;
    if (node->name == S_WALNUT)
        *((walnut_t *)node->data)->dropped = false;
    return true;
}

void settings_restat_game(data_t *src)
{
    if (src->game.menu.cliked && src->game.setting.restat.cliked) {
        clear_dlist(&src->lst, free_node);
        clear_dlist(&src->l_z, free_node);
        src->lst = NULL, src->l_z = NULL;
        src->round = 0;
        src->life = 3;
        src->game.setting.restat.cliked = false;
        src->score.points = 100;
    }
}

void settings_return_to_menu_page(data_t *src)
{
    if (src->game.setting.man_menu.cliked) {
        src->game.setting.restat.cliked = true;
        settings_restat_game(src);
        src->game.menu.cliked = false;
        src->win_page = MENU_PAGE;
        sfMusic_pause(src->game.music.name);
        sfMusic_play(src->menu.music.name);
        src->game.setting.man_menu.cliked = false;
    }
}

void set_game_settings(data_t *src)
{
    settings_restat_game(src);
    settings_return_to_menu_page(src);
    if (src->game.setting.box[1].cliked)
        src->game.menu.cliked = false;
}