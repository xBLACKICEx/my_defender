/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** map
*/

#include <my_defender.h>

void set_map_sprite(data_t *src, char *map_file)
{
    set_sfbase(&src->map, MAP_1, (s){0, 0, 0, 0, 1110, 602});
    if (map_file == NULL)
        open_map(src, MAP_TXT, creat_mini_map);
    else
        open_map(src, map_file, creat_mini_map);
}

void map_draw(data_t *src)
{
    if (src->win_page == GAME_PAGE) {
        sfRenderWindow_drawSprite(src->window, src->map.sp, NULL);
        for (node_t *tmp = src->lst_map->begin; tmp != NULL; tmp = tmp->next)
            sfRenderWindow_drawSprite(src->window,
            ((mini_map_t *)tmp->data)->sp, NULL);
    }
}

void map_free(sfbase_t *map)
{
    sfSprite_destroy(map->sp);
    sfTexture_destroy(map->tu);
}