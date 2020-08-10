/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu
*/

#include <my_defender.h>

void set_menu_sprite(menu_t *menu)
{
    set_sfbase(&menu->backgrund, MENU_BACKGROUND, (s){0, 0, 0, 0, 1110, 602});
    set_sfbase(&menu->btn[0], PLAY_BTN, (s){0.5, 0.95, 144, 0, 492, 144});
    set_sfbase(&menu->btn[1], SETTINGS_BTN, (s){0.98, 0.05, 0, 0, 32, 33});
    set_menu_settings_box_sprite(&menu->setting);
    menu->music.name = sfMusic_createFromFile(MENU_MUISC);
    sfMusic_play(menu->music.name);
    sfMusic_setVolume(menu->music.name, 50);
    menu->music.volume = sfMusic_getVolume(menu->music.name);
    sfMusic_setLoop(menu->music.name, sfTrue);
}

void menu_draw(data_t *src)
{
    if (src->win_page == MENU_PAGE) {
        sfRenderWindow_drawSprite(src->window, src->menu.backgrund.sp, NULL);
        for (int i = 0; i < 2; i++) {
            sfSprite_setTextureRect(src->menu.btn[i].sp, src->menu.btn[i].rec);
            sfRenderWindow_drawSprite(src->window, src->menu.btn[i].sp, NULL);
        }
        menu_settings_draw(src->win_page, src->window, &src->menu);
    }
}

void menu_free(menu_t *menu)
{
    sfMusic_destroy(menu->music.name);
    sfSprite_destroy(menu->backgrund.sp);
    sfTexture_destroy(menu->backgrund.tu);
    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(menu->btn[i].sp);
        sfTexture_destroy(menu->btn[i].tu);
    }
}