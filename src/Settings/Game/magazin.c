/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** magazin
*/

#include <my_defender.h>
#include <my_tools.h>

void set_magazin_product(data_t *src)
{
    set_sfbase(&src->stock[0], WALNUT_BUY, (s){0, 0.15, 0, 96, 96, 96});
    set_sfbase(&src->stock[1], SUN_BUY, (s){0, 0.35, 0, 96, 96, 96});
    set_sfbase(&src->stock[2], PEA_BUY, (s){0, 0.55, 0, 96, 96, 96});
    set_sfbase(&src->stock[3], BEEF_BUY, (s){0, 0.75, 0, 96, 96, 96});
    src->stock[0].p_name = S_WALNUT;
    src->stock[1].p_name = S_SUN;
    src->stock[2].p_name = S_PEA;
    src->stock[3].p_name = S_BEEF;
    src->stock[0].price = 25;
    src->stock[1].price = 50;
    src->stock[2].price = 100;
    src->stock[3].price = 125;
    for (int i = 0 ; i > 4; i++) src->stock[i].cliked = false;
    src->lst = NULL;
    src->score.points = 100;
    set_sftext_t(&src->score.text, (sfVector2f){15, 542}, sfWhite, 40);
    src->selected_plant.sp = NULL;
}

void selected_plant_draw(data_t *src)
{
    if (src->selected_plant.sp != NULL){
        sfSprite_setPosition(src->selected_plant.sp, src->mouse.pos);
        sfRenderWindow_drawSprite(src->window, src->selected_plant.sp, NULL);
    }
}

int draw_points(data_t *src)
{
    char *sc = my_itoa(src->score.points);
    sfText_setString(src->score.text.buf, sc);
    sfRenderWindow_drawText(src->window, src->score.text.buf, NULL);
    free(sc);
}

void magazin_draw(data_t *src)
{
    if (src->win_page == GAME_PAGE) {
        for (int i = 0; i < 4; i++) {
            check_total_points(src->score.points, &src->stock[i]);
            sfSprite_setTextureRect(src->stock[i].sp, src->stock[i].rec);
            sfRenderWindow_drawSprite(src->window, src->stock[i].sp, NULL);
        }
        draw_points(src);
        selected_plant_draw(src);
    }
}

void magazin_free(data_t *src)
{
    for (int i = 0; i < 4; i++) {
        sfSprite_destroy(src->stock[i].sp);
        sfTexture_destroy(src->stock[i].tu);
    }
    sfText_destroy(src->score.text.buf);
    sfFont_destroy(src->score.text.font);
}