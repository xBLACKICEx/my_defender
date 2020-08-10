/*
** EPITECH PROJECT, 2020
** new_runner_2019
** File description:
** my_defender_fonction_declartion
*/

#pragma onc

// ? defini stuct beet_t name
#define STRUCT_BEEF 6667
// ? defini stuct sun_t name
#define STRUCT_SUN 887
// ? defini stuct pea_t name
#define STRUCT_PEA 866
// ? defini stuct walnut_t name
#define STRUCT_WALNUT 867788
// ? defini stuct mini_mapt name
#define STRUCT_MINI_MAP 77773768

#define IS_STRUCT_BEEF(STRUCT) STRUCT == STRUCT_BEEF
#define IS_STRUCT_SUN(STRUCT) STRUCT == STRUCT_SUN
#define IS_STRUCT_PEA(STRUCT) STRUCT == STRUCT_PEA
#define IS_STRUCT_WALNUT(STRUCT) STRUCT == STRUCT_WALNUT

STRUCT_NAME_t set_fucon(fprt_t *fptr, STRUCT_NAME_t name);

/*window.c*/
void free_defender_data(data_t *src);
void events(data_t *src);

/*window.c*/
void window(data_t *src);
void change_window_page(data_t *src);

// Map
void set_map_sprite(data_t *src, char *map_file);
int open_map(data_t *src, char const *file, void(creat_src)(data_t *, char *));
mini_map_t *creat_mini_map_node(int x, int y, plants_texture_t texture);
void creat_mini_map(data_t *src, char *map);
void map_draw(data_t *src);
void map_free(sfbase_t *map);

// Menu
void set_menu_sprite(menu_t *menu);
void menu_draw(data_t *src);
void menu_event(data_t *src);
void set_menu_settings_box_sprite(menu_settings_t *set);
void fps_evnets_change_detected(data_t *src);

// Menu Settings
void fps_setting(data_t *src);
void fps_loop_update(data_t *src, int i);
void rest_menu_settings(data_t *src);
void menu_settings_draw(unsigned int win_page, sfRenderWindow *window,
                        menu_t *menu);
void get_old_menu_setting(data_t *src);
void set_volum_bar_btn_pos(data_t *src);
void check_update_setting_set(data_t *src);
void menu_settings_butun_event(data_t *src);
void mene_stting_volum_evnets(data_t *src);

// magazin
void set_magazin_product(data_t *src);
void check_total_points(unsigned int points, sfbase_t *stock);
void magazin_draw(data_t *src);
void magazin_event(data_t *src);
void magazin_free(data_t *src);
void my_put_nbr1(int n, char **stock);

// Music
void set_backgrund_muisc(data_t *src);
void free_muisc_list(data_t *src);

// Game plants
void creat_plants_list(data_t *src);
void creat_plants_pea(data_t *src, mini_map_t *mini_map);
void creat_plants_beet(data_t *src, mini_map_t *mini_map);
void creat_plants_sun(data_t *src, mini_map_t *mini_map);
void creat_plants_walnut(data_t *src, mini_map_t *mini_map);
void draw_pea(data_t *src, void *plant);
void draw_sun(data_t *src, void *plant);
void draw_beet(data_t *src, void *plant);
void draw_walnut(data_t *src, void *plant);
void plants_lst_draw(data_t *src);
void anim_pea(sfClock *clock, pea_t *pea);
void anim_sun(sfClock *clock, sun_t *sun);
void anim_beet(sfClock *clock, beet_t *beet);
void anim_walnut(sfClock *clock, walnut_t *walnut);

//  Game palan sun
void anim_sun_sun(ball_t *sun_sun);
void cheak_click_sun_sun(dlist_t **l_sun, data_t *src, unsigned int point);
void loop_sun_t_struct(data_t *src, void(*fon)());
void draw_sunflower_sun(dlist_t **l_sun, sfRenderWindow *win);
void set_sunflower_on_map(sun_t *sunflower, plants_texture_t texture);
void creat_sun_flower_ball(dlist_t **l_sun, int size, plants_texture_t texture,
                            int time);

// Game plant peashooter
void creat_pea_ball(dlist_t **l_ball, int leve, plants_texture_t texture,
                    sfVector2f pos);
void set_pea_leve(pea_t *pea, plants_texture_t texture);
void pea_ball_animation(ball_t *ball, sfVector2f pea_pos, bool s);
void draw_pea_ball(dlist_t **l_ball, pea_t *pea, data_t *src);
void set_pea_ball_on_map(pea_t *pea, plants_texture_t texture);

// Game plant beet
void creat_beet_ball(dlist_t **l_ball, int leve, plants_texture_t texture,
                    sfVector2f pos);
void set_beet_leve(beet_t *beet, plants_texture_t texture);
void beet_ball_animation(ball_t *ball, sfVector2f beet_pos, bool s);
void draw_beet_ball(dlist_t **l_ball, beet_t *beet, data_t *src);
void set_beet_ball_on_map(beet_t *beet, plants_texture_t texture);

// Game plants walnut
void set_walnut_leve(walnut_t *walnut, plants_texture_t texture);

// Game settings
void set_game_settings_sprite(game_t *set);
void set_game_settings_draw(unsigned int win_page, sfRenderWindow *window,
                            game_t *game);
void game_sets_btn_anim_event(data_t *src, sfVector2f mouse,
                            game_settings_t *set);
void game_menu_events(data_t *src);
void set_game_settings(data_t *src);

// ! free data
void free_node(node_t *node);
void free_pea_node(void *data);
void free_beet_node(void *data);
void free_sun_node(void *data);
void free_sun_sun_node(node_t *node);
void free_z1_node(void *data);
void free_z2_node(void *data);
void free_walnut_node(void *data);
void free_mini_map_node(void *data);
void free_game_settings(data_t *src);
void free_defender_data(data_t *data);
void free_sp_and_tu(sfbase_t *data, int size);
void free_plants_texture(plants_texture_t *texture);
void menu_free(menu_t *menu);
void menu_settings_free(data_t *src);

// Game Zombies
void zombies_lst_draw(data_t *src);
void z1_att_taime(z1_t *z1, dlist_t **l_plants);
void draw_z1(data_t *src, void *plant);
void creat_zombes_spwn(data_t *src, char *map);
z1_t *creat_z1_node(int x, int y, plants_texture_t texture);
STRUCT_NAME_t set_fucon_bool(bool_fprt_t *fptr, STRUCT_NAME_t name);
void check_colision_z1_plants(z1_t *z1, dlist_t **lst);
bool plants_and_zombies_dath(node_t *node, void *data);

void z2_att_taime(z2_t *z2, dlist_t **l_plants);
void draw_z2(data_t *src, void *plant);
void creat_zombes_spwn(data_t *src, char *map);
z2_t *creat_z2_node(int x, int y, plants_texture_t texture);
STRUCT_NAME_t set_fucon_bool(bool_fprt_t *fptr, STRUCT_NAME_t name);
void check_colision_z2_plants(z2_t *z2, dlist_t **lst);

void display_round(data_t *src);
void set_round_1(data_t *src);
void set_round_2(data_t *src);
void set_round_3(data_t *src);

// win and lose
void win_case(data_t *src);
void draw_win_lose(data_t *src);
void win_lose_event(data_t *src);
void win_restat_game(data_t *src);
void win_return_menu_page(data_t *src);
void win_lose_btn_click_events(data_t *src);