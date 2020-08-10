/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** setting_box
*/

#include <my_defender.h>

void set_game_settings_sprite(game_t *game)
{
    float j = 0.1;
    game->music.name = sfMusic_createFromFile(GAME_MUISC);
    sfMusic_setVolume(game->music.name, 50.0);
    sfMusic_setLoop(game->music.name, sfTrue);
    set_sfbase(&game->menu, GAME_MENU_BTN, (s){0.95, -0.005, 0, 0, 114, 32});
    set_sfbase(&game->setting.box[0], GAME_SETTINGS_BOX,
                (s){0.5, 0.65, 0, 0, 417, 485});
    set_sfbase(&game->setting.box[1], GAME_SETTINGS_BOX_OK,
                (s){0.5, 0.92, 0, 0, 412, 105});
    set_sfbase(&game->setting.restat, RESTAT_BTN, (s){0.5, 0.5, 0, 0, 208, 43});
    set_sfbase(&game->setting.man_menu, RETURN_MENU_BTN,
                (s){0.5, 0.6, 0, 0, 208, 43});
    set_sfbase(&game->setting.sound[0], SETTINGS_BAR,
                (s){0.5, 0.4125, 0, 0, 133, 7});
    set_sfbase(&game->setting.sound[1], SETTINGS_BAR_BTN,
                (s){0.5, 0.405, 0, 0, 25, 31});
    for (int i = 0; i < 3; i++, j += 0.05)
        set_sfbase(&game->life[i], HEART_IMG,  (s){j, 0.95, 0, 0, 32, 32});
}

void set_game_settings_draw(unsigned int win_page, sfRenderWindow *window,
                            game_t *game)
{
    if (win_page == GAME_PAGE) {
        sfRenderWindow_drawSprite(window, game->menu.sp, NULL);
        if (game->menu.cliked) {
            for (int i = 0; i < 2; i++) {
                sfRenderWindow_drawSprite(window, game->setting.box[i].sp,
                                            NULL);
                sfRenderWindow_drawSprite(window, game->setting.sound[i].sp,
                                            NULL);
            }
            sfSprite_setPosition(game->setting.sound[1].sp,
                                game->setting.sound[1].pos);
            sfSprite_setTextureRect(game->setting.sound[1].sp,
                                    game->setting.sound[1].rec);
            sfRenderWindow_drawSprite(window, game->setting.restat.sp, NULL);
            sfRenderWindow_drawSprite(window, game->setting.man_menu.sp, NULL);
        }
    }
}

void free_game_settings(data_t *src)
{
    free_sp_and_tu(src->game.setting.box, 2);
    free_sp_and_tu(src->game.setting.sound, 2);
    free_sp_and_tu(&src->game.setting.restat, 1);
    free_sp_and_tu(&src->game.setting.man_menu, 1);
    free_sp_and_tu(&src->game.menu, 1);
    sfMusic_destroy(src->game.music.name);
}