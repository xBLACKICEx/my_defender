/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu_event
*/

#include <my_defender.h>

void menu_button_event(sfEvent event, sfVector2f mouse, menu_t *menu)
{
    if (check_btn_touched(mouse, menu->btn[1].pos, menu->btn[1].rec)) {
        menu->btn[1].rec.left = 32;
        if (button_clicked(event, mouse, menu->btn[1].pos, menu->btn[1].rec))
            menu->btn[1].cliked = !menu->btn[1].cliked;
    } else
        menu->btn[1].rec.left = 0;
    if (check_btn_touched(mouse, menu->btn[0].pos, menu->btn[0].rec) &&
                                                !menu->btn[1].cliked) {
        menu->btn[0].rec.top = 0;
        if (button_clicked(event, mouse, menu->btn[0].pos, menu->btn[0].rec))
            menu->btn[0].cliked = !menu->btn[0].cliked;
    } else
        menu->btn[0].rec.top = 144;
}

void menu_event(data_t *src)
{

    if (src->win_page == MENU_PAGE) {
        get_old_menu_setting(src);
        if (is_env_key_pressed(src->event, sfKeyEscape))
            src->menu.btn[1].cliked = !src->menu.btn[1].cliked;
        menu_button_event(src->event, src->mouse.pos, &src->menu);
        if (src->menu.btn[1].cliked && !src->menu.setting.box[1].cliked) {
            src->menu.setting.box[0].cliked = true;
            mene_stting_volum_evnets(src);
            fps_evnets_change_detected(src);
            menu_settings_butun_event(src);
        }
        check_update_setting_set(src);
    }
}