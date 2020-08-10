/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** update_menu_settings
*/

#include <my_defender.h>

void get_old_menu_setting(data_t *src)
{
    int i = 0;

    if ((check_btn_touched(src->mouse.pos, src->menu.btn[1].pos,
                            src->menu.btn[1].rec) &&
            sfMouse_isButtonPressed(sfMouseLeft) ||
            is_env_key_pressed(src->event, sfKeyEscape)) &&
        !src->menu.btn[1].cliked) {
        src->menu.music.tmp_volume = src->menu.music.volume;
        src->menu.setting.pos_tmp = src->menu.setting.sound[1].pos;
        for (; i < 4 && !src->menu.setting.fps[i].cliked; i++);
        src->menu.setting.tmp_fps = i;
    }
}

void rest_menu_settings(data_t *src)
{
    src->menu.music.volume = src->menu.music.tmp_volume;
    sfMusic_setVolume(src->menu.music.name, src->menu.music.volume);
    src->menu.setting.sound[1].pos = src->menu.setting.pos_tmp;
    fps_loop_update(src, src->menu.setting.tmp_fps);
}

void check_update_setting_set(data_t *src)
{
    if (!src->menu.btn[1].cliked && src->menu.setting.box[0].cliked &&
        !src->menu.setting.box[1].cliked) {
        rest_menu_settings(src);
        src->menu.setting.box[0].cliked = false;
    } else if (src->menu.btn[1].cliked && src->menu.setting.box[1].cliked) {
        src->menu.setting.box[0].cliked = false;
        src->menu.setting.box[1].cliked = false;
        src->menu.btn[1].cliked = false;
    }
}