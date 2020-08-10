/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** win_louse
*/

#include <my_defender.h>

void draw_win_lose(data_t *src)
{
    if (src->win_page == WIN_PAGE || src->win_page == LOSE_PAGE) {
        if (src->win_page == WIN_PAGE)
            sfRenderWindow_drawSprite(src->window, src->w_l.win.sp, NULL);
        if (src->win_page == LOSE_PAGE)
            sfRenderWindow_drawSprite(src->window, src->w_l.lose.sp, NULL);
        sfRenderWindow_drawSprite(src->window, src->w_l.restat.sp, NULL);
        sfRenderWindow_drawSprite(src->window, src->w_l.man_menu.sp, NULL);
        sfRenderWindow_drawSprite(src->window, src->w_l.exit.sp, NULL);
    }
}

void win_case(data_t *src)
{
    if (src->l_z == NULL && src->round == 3) {
        src->win_page = WIN_PAGE;
    }
    if ((src->life <= 0 || (src->lst == NULL && src->score.points == 0)) &&
        src->win_page != LOSE_PAGE) {
        src->win_page = LOSE_PAGE;
        src->w_l.restat.pos.x = 0.1 * (1110 - src->w_l.restat.rec.width);
        src->w_l.restat.pos.y = 0.2 * (602 - src->w_l.restat.rec.height);
        src->w_l.man_menu.pos.x = 0.1 * (1110 - src->w_l.man_menu.rec.width);
        src->w_l.man_menu.pos.y = 0.3 * (602 - src->w_l.man_menu.rec.height);
        src->w_l.exit.pos.x = 0.1 * (1110 - src->w_l.exit.rec.width);
        src->w_l.exit.pos.y = 0.4 * (602 - src->w_l.exit.rec.height);
        sfSprite_setPosition(src->w_l.restat.sp, src->w_l.restat.pos);
        sfSprite_setPosition(src->w_l.man_menu.sp, src->w_l.man_menu.pos);
        sfSprite_setPosition(src->w_l.exit.sp, src->w_l.exit.pos);
    }
    draw_win_lose(src);
}