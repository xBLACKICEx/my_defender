/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** csfml_tools1
*/

#include <my_defender.h>

bool check_btn_touched(sfVector2f mouse, sfVector2f pos, sfIntRect rect)
{
    if (mouse.x >= pos.x && mouse.x <= pos.x + rect.width && mouse.y >= pos.y &&
        mouse.y <= pos.y + rect.height)
        return (true);
    return (false);
}

void set_sfbase(sfbase_t *data, char *img, s src)
{
    data->sp = sfSprite_create();
    data->tu = sfTexture_createFromFile(img, NULL);
    data->cliked = false;
    sfSprite_setTexture(data->sp, data->tu, sfTrue);
    data->rec.top = src.top;
    data->rec.left = src.left;
    data->rec.width = src.width;
    data->rec.height = src.height;
    data->pos.x = src.x * (1110 - data->rec.width);
    data->pos.y = src.y * (602 - data->rec.height);
    sfSprite_setTextureRect(data->sp, data->rec);
    sfSprite_setPosition(data->sp, data->pos);
}

void set_csfml_btn_animation(sfVector2f mouse_pos, sfbase_t *button, int offset,
                            int *rec_side)
{
    int tmp = *rec_side;
    if (check_btn_touched(mouse_pos, button->pos, button->rec)) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            *rec_side = offset * 2;
        else
            *rec_side = offset;
    } else
        *rec_side = 0;
    sfSprite_setTextureRect(button->sp, button->rec);
}

void set_sftext_t(sftext_t *sftext, sfVector2f pos, sfColor color,
                unsigned int size)
{
    sftext->buf = sfText_create();
    sftext->font = sfFont_createFromFile(MY_FONT);
    sfText_setFont(sftext->buf, sftext->font);
    sfText_setCharacterSize(sftext->buf, size);
    sfText_setColor(sftext->buf, sfWhite);
    sfText_setPosition(sftext->buf, pos);
}