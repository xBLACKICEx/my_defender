/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** csfml_tools2
*/

#include <my_defender.h>

bool tow_box_touched(sfVector2f pos_1, sfIntRect rect_1, sfVector2f pos_2,
                    sfIntRect rect_2)
{
    if (pos_1.x + rect_1.width > pos_2.x && pos_1.y + rect_1.height > pos_2.y &&
        pos_2.x + rect_2.width > pos_1.x && pos_2.y + rect_2.height > pos_1.y)
        return true;
    else
        return false;
}

void creat_clock(sfClock **clock, unsigned int num)
{
    for (int i = 0; i < num; i++) clock[i] = sfClock_create();
}

void free_clock(sfClock **clock, unsigned int num)
{
    for (int i = 0; i < num; i++) sfClock_destroy(clock[i]);
}

bool i_nill(void)
{
    return false;
}

STRUCT_NAME_t set_fucon_bool(bool_fprt_t *fptr, STRUCT_NAME_t name)
{
    unsigned char i = 0;

    for (; fptr[i].name != -1 && fptr[i].name != name; i++);
    return i;
}