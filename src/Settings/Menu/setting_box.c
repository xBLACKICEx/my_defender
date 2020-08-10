/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** setting_box
*/

#include <my_defender.h>

void set_menu_settings_box_sprite(menu_settings_t *set)
{
    int j = 30;
    sfVector2f pos = {0.425, 0.6};

    set_sfbase(&set->box[0], SETTINGS_BOX, (s){0.5, 0.65, 0, 0, 417, 485});
    set_sfbase(&set->box[1], SETTINGS_BOX_OK, (s){0.5, 0.92, 0, 0, 412, 105});
    set_sfbase(&set->sound[0], SETTINGS_BAR, (s){0.5, 0.4125, 0, 0, 133, 7});
    set_sfbase(&set->sound[1], SETTINGS_BAR_BTN, (s){0.5, 0.405, 0, 0, 25, 31});
    for (int i = 0; i < 4; i++, pos.x += 0.05, j *= 2) {
        set_sfbase(&set->fps[i], YES_NO, (s){pos.x, pos.y, 0, 0, 39, 34});
        set->fps[i].price = j;
    }
    set->pos_tmp = set->sound[1].pos;
    set->fps[1].cliked = true;
    set->fps[1].rec.left = 39;
    set->fps[3].price = 144;
}

void set_volum_bar_btn_pos(data_t *src)
{
    float p = src->menu.music.volume * 0.01;
    src->menu.setting.sound[1].pos.x = p *
    (133 - src->menu.setting.sound[1].rec.width) +
    src->menu.setting.sound[0].pos.x;
    sfSprite_setPosition(src->menu.setting.sound[1].sp,
                                            src->menu.setting.sound[1].pos);
}

void menu_settings_draw(unsigned int win_page,
sfRenderWindow *window, menu_t *menu)
{
    if (win_page == MENU_PAGE && menu->btn[1].cliked &&
                                !menu->setting.box[1].cliked) {
        sfRenderWindow_drawSprite(window, menu->setting.box[0].sp, NULL);
        sfSprite_setTextureRect(menu->setting.box[1].sp,
                                                menu->setting.box[1].rec);
        sfSprite_setPosition(menu->setting.sound[1].sp,
                                                menu->setting.sound[1].pos);
        sfRenderWindow_drawSprite(window, menu->setting.box[1].sp, NULL);
        sfRenderWindow_drawSprite(window, menu->setting.sound[0].sp, NULL);
        sfRenderWindow_drawSprite(window, menu->setting.sound[1].sp, NULL);
        for (int i = 0; i < 4; i++) {
            sfSprite_setTextureRect(menu->setting.fps[i].sp,
                                                menu->setting.fps[i].rec);
            sfRenderWindow_drawSprite(window, menu->setting.fps[i].sp, NULL);
        }
    }
}

void menu_settings_free(data_t *src)
{
    free_sp_and_tu(src->menu.setting.box, 2);
    free_sp_and_tu(src->menu.setting.sound, 2);
    free_sp_and_tu(src->menu.setting.fps, 4);
}

void fps_setting(data_t *src)
{
    for (int i = 0; i < 4; i++) {
        if (src->menu.setting.fps[i].cliked)
            sfRenderWindow_setFramerateLimit(src->window,
                        src->menu.setting.fps[i].price);
    }
}