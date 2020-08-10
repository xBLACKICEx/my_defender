/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** window
*/

#include <my_defender.h>

void get_mouse_postion(data_t *src)
{
    sfVector2i v = sfMouse_getPositionRenderWindow(src->window);
    src->mouse.pos.x = v.x;
    src->mouse.pos.y = v.y;
}

void change_window_page(data_t *src)
{
    if (src->menu.btn[0].cliked == true &&
        src->menu.setting.box[0].cliked == false) {
        src->win_page = GAME_PAGE;
        sfMusic_pause(src->menu.music.name);
        sfMusic_play(src->game.music.name);
        src->menu.btn[0].cliked = false;
    }
}

void events(data_t *src)
{
    while (sfRenderWindow_pollEvent(src->window, &src->event)) {
        if (src->event.type == sfEvtClosed)
            sfRenderWindow_close(src->window);
        if (is_env_key_pressed(src->event, sfKeyEscape))
            src->key.esc = !src->key.esc;
        menu_event(src);
        win_lose_event(src);
        magazin_event(src);
        game_menu_events(src);
        creat_plants_list(src);
        loop_sun_t_struct(src, cheak_click_sun_sun);
    }
}

void window(data_t *src)
{
    src->window = sfRenderWindow_create((sfVideoMode){1110, 602, 32},
    NAME, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(src->window, 60);
    while (sfRenderWindow_isOpen(src->window)) {
        change_window_page(src);
        fps_setting(src);
        get_mouse_postion(src);
        events(src);
        sfRenderWindow_clear(src->window, sfBlack);
        menu_draw(src);
        map_draw(src);
        plants_lst_draw(src);
        zombies_lst_draw(src);
        set_game_settings(src);
        set_game_settings_draw(src->win_page, src->window, &src->game);
        magazin_draw(src);
        win_case(src);
        sfRenderWindow_display(src->window);
    }
}