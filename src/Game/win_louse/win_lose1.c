/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** win_lose2
*/

#include <my_defender.h>

void win_return_menu_page(data_t *src)
{
    if (src->w_l.man_menu.cliked) {
        clear_dlist(&src->lst, free_node);
        clear_dlist(&src->l_z, free_node);
        src->lst = NULL, src->l_z = NULL;
        src->round = 0;
        src->life = 3;
        src->w_l.man_menu.cliked = false;
        src->win_page = MENU_PAGE;
        src->score.points = 100;
    }
}

void win_lose_btn_click_events(data_t *src)
{
    if (button_relesed(src->event, src->mouse.pos, src->w_l.restat.pos,
                        src->w_l.restat.rec))
        src->w_l.restat.cliked = !src->w_l.restat.cliked;
    if (button_relesed(src->event, src->mouse.pos, src->w_l.exit.pos,
                        src->w_l.exit.rec))
        src->w_l.exit.cliked = !src->w_l.exit.cliked;
    if (button_relesed(src->event, src->mouse.pos, src->w_l.man_menu.pos,
                        src->w_l.man_menu.rec))
        src->w_l.man_menu.cliked = !src->w_l.man_menu.cliked;
}

void win_restat_game(data_t *src)
{
    if (src->w_l.restat.cliked) {
        clear_dlist(&src->lst, free_node);
        clear_dlist(&src->l_z, free_node);
        src->lst = NULL, src->l_z = NULL;
        src->round = 0;
        src->life = 3;
        src->win_page = GAME_PAGE;
        src->w_l.restat.cliked = false;
        src->score.points = 100;
    }
}

void win_lose_event(data_t *src)
{
    if ((src->win_page == WIN_PAGE || src->win_page == LOSE_PAGE)) {
        set_csfml_btn_animation(src->mouse.pos, &src->w_l.restat, 208,
                                &src->w_l.restat.rec.left);
        set_csfml_btn_animation(src->mouse.pos, &src->w_l.man_menu, 208,
                                &src->w_l.man_menu.rec.left);
        set_csfml_btn_animation(src->mouse.pos, &src->w_l.exit, 208,
                                &src->w_l.exit.rec.left);
        win_lose_btn_click_events(src);
        if (src->w_l.exit.cliked) sfRenderWindow_close(src->window);
        win_restat_game(src);
        win_return_menu_page(src);
    }
}