/*
** EPITECH PROJECT, 2020
** new_runner_2019
** File description:
** csfml_tools_fonction_declartion
*/

#pragma once
#include <stdbool.h>


// craet img spite texture one line fonction
void creat_img_sprite(sfSprite **sprite, sfTexture **texture, char *img);

// Check if the two img (sprite) collision
// pos_1, pos_1: the minimum value of sprite x, y
// rect is the maximum
// Detection accuracy: cube
bool tow_box_touched(sfVector2f pos_1, sfIntRect rect_1, sfVector2f pos_2,
                    sfIntRect rect_2);
// 1 Get img (sprite) rectangle automatically
// 2 Position (pos) img percentage position on screen
// (Screen 1920 × 1080 standard) 0.1 = 10%, 0.5 = 50%
void set_sfbase(sfbase_t *data, char *img, s src);

// char size is totall number of sprite loop to check
bool button_clicked(sfEvent event, sfVector2f mouse, sfVector2f pos,
                    sfIntRect rec);
bool button_relesed(sfEvent event, sfVector2f mouse, sfVector2f pos,
                    sfIntRect rec);

bool check_btn_touched(sfVector2f mouse, sfVector2f pos, sfIntRect rect);

// check events key pressed
bool is_env_key_pressed(sfEvent event, sfKeyCode code);

// creat_text
sfText *creat_defaut_text(sfColor color, int size, char *texts, sfVector2f pos);
void set_csfml_btn_animation(sfVector2f mouse_pos, sfbase_t *button, int offset,
                            int *rec_side);
void set_sftext_t(sftext_t *sftext, sfVector2f pos, sfColor color,
                    unsigned int size);
void move_rect(sfIntRect *rect_pea, int offset, int max_value);

bool i_nill(void);
void move_rect_deth(sfIntRect *rect_pea, int offset, int max_value);
void free_clock(sfClock **clock, unsigned int num);
void creat_clock(sfClock **clock, unsigned int num);
void set_sprite(sfSprite **sprite, sfTexture **texture);