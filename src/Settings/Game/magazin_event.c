/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** magazin_event
*/

#include <my_defender.h>

void check_total_points(unsigned int points, sfbase_t *stock)
{
    if (points >= stock->price)
        stock->rec.left = 0;
    else
        stock->rec.left = 96;
}

void check_selection_stocks(data_t *src)
{
    for (int i = 0; i < 4; i++)
        if (src->score.points >= src->stock[i].price &&
            button_clicked(src->event, src->mouse.pos,
                            src->stock[i].pos, src->stock[i].rec)
            && src->selected_plant.sp == NULL) {
            src->score.points -= src->stock[i].price;
            src->selected_plant.sp = sfSprite_copy(src->stock[i].sp);
            src->selected_plant.pos = src->mouse.pos;
            src->stock[i].cliked = true;
            src->selected_plant.dropped = &src->stock[i].cliked;
            src->selected_plant.name = src->stock[i].p_name;
        } else if (src->selected_plant.sp != NULL && src->stock[i].cliked &&
            src->event.type == sfEvtMouseButtonPressed &&
            src->event.mouseButton.button == sfMouseRight) {
                sfSprite_destroy(src->selected_plant.sp);
                src->selected_plant.sp = NULL;
                src->score.points += src->stock[i].price;
                src->stock[i].cliked = false;
        }
}

void magazin_event(data_t *src)
{
    check_selection_stocks(src);
}