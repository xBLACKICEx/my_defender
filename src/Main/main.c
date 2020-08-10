/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** main
*/

#include <my_printf.h>
#include <my_tools.h>
#include <my_defender.h>

void set_plants_texture(plants_texture_t *texture)
{
    texture->beet_a1 = sfTexture_createFromFile(BEET_ALIVE, NULL);
    texture->beet_a2 = sfTexture_createFromFile(BEET_ALIVE2, NULL);
    texture->beet_die = sfTexture_createFromFile(BEET_DIE, NULL);
    texture->bullet = sfTexture_createFromFile(BEET_BULLET, NULL);
    texture->pea_a1 = sfTexture_createFromFile(PEA_ALIVE, NULL);
    texture->pea_a2 = sfTexture_createFromFile(PEA_ALIVE2, NULL);
    texture->pea_a3 = sfTexture_createFromFile(PEA_ALIVE3, NULL);
    texture->pea_die = sfTexture_createFromFile(PEA_DIE, NULL);
    texture->ball = sfTexture_createFromFile(PEA_BALL, NULL);
    texture->flower_alive = sfTexture_createFromFile(SUN_ALIVE, NULL);
    texture->flower_die = sfTexture_createFromFile(SUN_DIE, NULL);
    texture->sun = sfTexture_createFromFile(SUN_SUN, NULL);
    texture->walnut_a1 = sfTexture_createFromFile(WALNUT_ALIVE, NULL);
    texture->walnut_a2 = sfTexture_createFromFile(WALNUT_ALIVE2, NULL);
    texture->walnut_die = sfTexture_createFromFile(WALNUT_DIE, NULL);
    texture->mini_map = sfTexture_createFromFile(MINI_MAP, NULL);
    texture->z1_alive = sfTexture_createFromFile(Z1_ALIVE, NULL);
    texture->z1_die = sfTexture_createFromFile(Z1_DIE, NULL);
    texture->z2_alive = sfTexture_createFromFile(Z2_ALIVE, NULL);
    texture->z2_die = sfTexture_createFromFile(Z2_DIE, NULL);
}

void set_win_lose_img(data_t *src)
{
    set_sfbase(&src->w_l.win, WIN_IMG, (s){0.5, 0.5, 0, 0, 869, 602});
    set_sfbase(&src->w_l.lose, LOSE_IMG, (s){0.5, 0.5, 0, 0, 1111, 602});
    set_sfbase(&src->w_l.restat, RESTAT_BTN, (s){0.2, 0.1, 0, 0, 208, 43});
    set_sfbase(&src->w_l.man_menu, RETURN_MENU_BTN,
                (s){0.5, 0.1, 0, 0, 208, 43});
    set_sfbase(&src->w_l.exit, EXIT_BTN,
                (s){0.8, 0.1, 0, 0, 208, 43});
}

void help_print(void)
{
    my_printf("Les regles de notre Defender sont"
            "simple, protege la maison et posant des"
            "plantes dans ton jardin afin de tuer les vagues de"
            "zombies en approche\n" "Tu auras acces au volume du son dans le"
            "main menu et en plaine partie, tu pourras egalemant quitter la"
            " partie et meme la restart si tu as mal commencé"
            "Bonne chance a toi\n");
}

void set_data(data_t **data, char *av)
{
    (*data)->key.esc = false;
    set_sftext_t(&(*data)->t_round, (sfVector2f){555, 301}, sfWhite, 50);
    set_menu_sprite(&(*data)->menu);
    set_magazin_product((*data));
    set_game_settings_sprite(&(*data)->game);
    set_plants_texture(&(*data)->textures);
    set_map_sprite((*data), av);
    set_win_lose_img((*data));
}

int main(int ac, char *av[])
{
    data_t *data = malloc(sizeof(data_t));
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        help_print();
    else {
        int n = rand() % 32767 + 1;
        data->r = NULL;
        data->round = 0;
        data->life = 3;
        data->lst = NULL;
        data->l_z = NULL;
        data->clock.clock1 = NULL;
        set_data(&data, av[1]);
        srand(n);
        data->win_page = MENU_PAGE;
        window(data);
        free_defender_data(data);
    }
}