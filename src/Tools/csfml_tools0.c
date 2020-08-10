/*
** EPITECH PROJECT, 2020
** new_runner_2019
** File description:
** csfml_tools0
*/
#include <my_defender.h>

bool button_clicked(sfEvent event, sfVector2f mouse, sfVector2f pos,
                    sfIntRect rec)
{
    if (check_btn_touched(mouse, pos, rec))
        if (event.type == sfEvtMouseButtonPressed &&
            event.mouseButton.button == sfMouseLeft)
            return true;
        else
            return false;
}

bool button_relesed(sfEvent event, sfVector2f mouse, sfVector2f pos,
                    sfIntRect rec)
{
    if (check_btn_touched(mouse, pos, rec))
        if (event.type == sfEvtMouseButtonReleased &&
            event.mouseButton.button == sfMouseLeft)
            return true;
        else
            return false;
}

void creat_img_sprite(sfSprite **sprite, sfTexture **texture, char *img)
{
    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile(img, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
}

void set_sprite(sfSprite **sprite, sfTexture **texture)
{
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, *texture, sfTrue);
}

bool is_env_key_pressed(sfEvent event, sfKeyCode code)
{
    if (event.type == sfEvtKeyPressed && event.key.code == code)
        return true;
    else
        return false;
}