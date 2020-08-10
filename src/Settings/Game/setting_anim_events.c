/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** setting_btn_animation_events
*/

#include <my_defender.h>

void game_sets_btn_anim_event(data_t *src, sfVector2f mouse,
                                game_settings_t *set)
{
    set_csfml_btn_animation(mouse, &set->box[1], 417, &set->box[1].rec.left);
    if (!src->game.menu.cliked)
        set_csfml_btn_animation(mouse, &src->game.menu, 114,
                                &src->game.menu.rec.left);
    set_csfml_btn_animation(mouse, &set->restat, 208, &set->restat.rec.left);
    set_csfml_btn_animation(mouse, &set->man_menu, 208,
                            &set->man_menu.rec.left);
}

void game_settings_btn_evnets(sfEvent event, sfVector2f mouse, game_t *game,
                                game_settings_t *set)
{
    if (game->menu.cliked == false) {
        set->restat.cliked = false;
        set->box[1].cliked = false;
        set->box[0].cliked = false;
        set->man_menu.cliked = false;
    }
    if (button_relesed(event, mouse, game->menu.pos, game->menu.rec) ||
        is_env_key_pressed(event, sfKeyEscape)) {
        game->menu.cliked = !game->menu.cliked;
        game->menu.rec.left = 114 * 2;
        sfSprite_setTextureRect(game->menu.sp, game->menu.rec);
    }
    if (game->menu.cliked) {
        if (button_relesed(event, mouse, set->restat.pos, set->restat.rec))
            set->restat.cliked = !set->restat.cliked;
        if (button_relesed(event, mouse, set->box[1].pos, set->box[1].rec))
            set->box[1].cliked = !set->box[1].cliked;
        if (button_relesed(event, mouse, set->man_menu.pos, set->box[1].rec))
            set->man_menu.cliked = !set->man_menu.cliked;
    }
}

void game_stting_volum_evnets(data_t *src)
{
    float x;
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        check_btn_touched(src->mouse.pos, src->game.setting.sound[1].pos,
                        src->game.setting.sound[1].rec)) {
        x = ((src->game.setting.sound[1].pos.x -
                src->game.setting.sound[0].pos.x) +
                25 * src->game.music.volume * 0.01) *
                100 / 133;
        if (src->game.setting.sound[1].pos.x > 610) {
            x = 100;
            src->game.setting.sound[1].pos.x = 605;
        } else if (src->game.setting.sound[1].pos.x < 490) {
            x = 0;
            src->game.setting.sound[1].pos.x = 490;
        }
        if (src->mouse.pos.x > 500 && src->mouse.pos.x < 610) {
            src->game.setting.sound[1].pos.x = src->mouse.pos.x - 12.5;
            sfMusic_setVolume(src->game.music.name, x);
            src->game.music.volume = sfMusic_getVolume(src->game.music.name);
        }
    }
}

void game_menu_events(data_t *src)
{
    game_sets_btn_anim_event(src, src->mouse.pos, &src->game.setting);
    game_settings_btn_evnets(src->event, src->mouse.pos, &src->game,
                            &src->game.setting);
    game_stting_volum_evnets(src);
}