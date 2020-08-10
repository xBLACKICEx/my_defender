/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** free_data
*/

#include <my_defender.h>

void free_plants_texture(plants_texture_t *texture)
{
    sfTexture_destroy(texture->beet_a1);
    sfTexture_destroy(texture->beet_a2);
    sfTexture_destroy(texture->beet_die);
    sfTexture_destroy(texture->bullet);
    sfTexture_destroy(texture->pea_a1);
    sfTexture_destroy(texture->pea_a2);
    sfTexture_destroy(texture->pea_a3);
    sfTexture_destroy(texture->pea_die);
    sfTexture_destroy(texture->ball);
    sfTexture_destroy(texture->flower_alive);
    sfTexture_destroy(texture->flower_die);
    sfTexture_destroy(texture->sun);
    sfTexture_destroy(texture->walnut_a1);
    sfTexture_destroy(texture->walnut_a2);
    sfTexture_destroy(texture->walnut_die);
    sfTexture_destroy(texture->mini_map);
    sfTexture_destroy(texture->z1_alive);
    sfTexture_destroy(texture->z1_die);
    sfTexture_destroy(texture->z2_alive);
    sfTexture_destroy(texture->z2_die);
}

void free_node(node_t *node)
{
    fprt_t fptr[] = {{S_WALNUT, free_walnut_node},
                    {S_SUN, free_sun_node},
                    {S_PEA, free_pea_node},
                    {S_BEEF, free_beet_node},
                    {S_Z1, free_z1_node},
                    {S_Z2, free_z2_node},
                    {S_MINI_MAP, free_mini_map_node},
                    {0, NULL}};
    fptr[set_fucon(fptr, node->name)].ptr(node->data);
    free(node);
}

void free_defender_data(data_t *data)
{
    sfRenderWindow_destroy(data->window);
    menu_settings_free(data);
    free_game_settings(data);
    menu_free(&data->menu);
    map_free(&data->map);
    free_plants_texture(&data->textures);
    clear_dlist(&data->lst, free_node);
    clear_dlist(&data->l_z, free_node);
    clear_dlist(&data->lst_map, free_node);
    magazin_free(data);
    free(data);
}

void free_sp_and_tu(sfbase_t *data, int size)
{
    for (int i = 0; i < size; i++) {
        sfSprite_destroy(data[i].sp);
        sfTexture_destroy(data[i].tu);
    }
}