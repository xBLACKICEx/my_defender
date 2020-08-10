/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** settings_box_events
*/

#include <my_defender.h>
#include <my_printf_tools.h>
#include <my_printf.h>

void fps_loop_update(data_t *src, int i)
{
    for (int j = 0; j < 4; j++) {
        if (j == i) {
            src->menu.setting.fps[j].cliked = true;
            src->menu.setting.fps[j].rec.left = 39;
            continue;
        } else {
            src->menu.setting.fps[j].cliked = false;
            src->menu.setting.fps[j].rec.left = 0;
        }
    }
}

void fps_evnets_change_detected(data_t *src)
{
    for (int i = 0; i < 4; i++) {
        if (button_clicked(src->event, src->mouse.pos,
            src->menu.setting.fps[i].pos, src->menu.setting.fps[i].rec)) {
            fps_loop_update(src, i);
        }
    }
}

void mene_stting_volum_evnets(data_t *src)
{
    float x;

    if (src->menu.btn[1].cliked && sfMouse_isButtonPressed(sfMouseLeft) &&
        check_btn_touched(src->mouse.pos, src->menu.setting.sound[1].pos,
                                        src->menu.setting.sound[1].rec)) {
        x = ((src->menu.setting.sound[1].pos.x -
            src->menu.setting.sound[0].pos.x) +
            25 * src->menu.music.volume * 0.01) * 100 / 133;
        if (src->menu.setting.sound[1].pos.x > 610) {
            x = 100;
            src->menu.setting.sound[1].pos.x = 605;
        } else if (src->menu.setting.sound[1].pos.x < 490) {
            x = 0;
            src->menu.setting.sound[1].pos.x = 490;
        }
        if (src->mouse.pos.x > 500 && src->mouse.pos.x < 610) {
            src->menu.setting.sound[1].pos.x = src->mouse.pos.x - 12.5;
            sfMusic_setVolume(src->menu.music.name, x);
            src->menu.music.volume = sfMusic_getVolume(src->menu.music.name);
        }
    }
}

void menu_settings_butun_event(data_t *src)
{
    if (check_btn_touched(src->mouse.pos, src->menu.setting.box[1].pos,
                                            src->menu.setting.box[1].rec)) {
        src->menu.setting.box[1].rec.left = 412;
    } else
        src->menu.setting.box[1].rec.left = 0;
    if (button_clicked(src->event, src->mouse.pos,
        src->menu.setting.box[1].pos, src->menu.setting.box[1].rec))
        src->menu.setting.box[1].cliked = !src->menu.setting.box[1].cliked;
}