/*
** EPITECH PROJECT, 2020
** new_runner_2019
** File description:
** my_defender_struct
*/

#ifndef MY_DENFENDER_STRUCT_H_
#define MY_DENFENDER_STRUCT_H_

/*LIB SFML*/
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdbool.h>

#ifdef STRUCT_NAME_t
typedef enum STRUCT_NAME_e {
    S_WALNUT,
    S_SUN,
    S_BEEF,
    S_PEA,
    S_MINI_MAP,
    S_Z1,
    S_Z2
} STRUCT_NAME_t;
#endif

typedef struct fptr {
    STRUCT_NAME_t name;
    void (*ptr)();
} fprt_t;


typedef struct s_bool_fptr {
    STRUCT_NAME_t name;
    bool (*ptr)();
} bool_fprt_t;

typedef struct {
    sfSprite *sp;
    sfVector2f pos;
    sfIntRect rec;
    sfClock *clock;
    sfVector2f speed;
} ball_t;

typedef struct s_z1 {
    int att;
    int life;
    int in_death;
    bool *dropped;
    unsigned int level;
    unsigned int interval;
    sfClock *clock[2];
    sfSprite *alive;
    sfSprite *die;
    sfVector2f pos;
    sfVector2f speed;
    sfIntRect rec;
} z1_t;

typedef struct s_z2 {
    int att;
    int life;
    int in_death;
    unsigned int w_max;
    unsigned int interval;
    unsigned int level;
    bool *dropped;
    sfClock *clock[2];
    sfSprite *alive;
    sfSprite *die;
    sfVector2f pos;
    sfVector2f speed;
    sfIntRect rec;
} z2_t;

typedef struct s_beet {
    int life;
    int in_death;
    unsigned int w_max;
    unsigned int level;
    unsigned int exp;
    unsigned int att;
    bool *dropped;
    sfSprite *die;
    sfIntRect rec;
    sfClock *clock;
    sfVector2f pos;
    sfSprite *alive;
    dlist_t *l_ball;
} beet_t;

typedef struct s_sun {
    int life;
    int in_death;
    float seconds;
    unsigned int level;
    unsigned int point;
    bool *dropped;
    sfClock *clock[3];
    sfSprite *alive;
    sfSprite *die;
    sfVector2f pos;
    sfIntRect rec;
    dlist_t *l_sun;
} sun_t;

typedef struct s_pea {
    int att;
    int life;
    int in_death;
    bool *dropped;
    unsigned int level;
    unsigned int exp;
    sfSprite *alive;
    sfSprite *die;
    sfVector2f pos;
    sfIntRect rec;
    sfClock *clock;
    dlist_t *l_ball;
} pea_t;

typedef struct s_walnut {
    int life;
    int in_death;
    unsigned int exp;
    unsigned int level;
    unsigned int w_max;
    bool *dropped;
    sfIntRect rec;
    sfSprite *die;
    sfVector2f pos;
    sfClock *clock;
    sfSprite *alive;
} walnut_t;

typedef struct s_sfbase {
    bool cliked;
    unsigned int price;
    unsigned int name;
    STRUCT_NAME_t p_name;
    sfSprite *sp;
    sfTexture *tu;
    sfVector2f pos;
    sfIntRect rec;
} sfbase_t;

typedef struct s_music {
    sfMusic *name;
    float volume, tmp_volume;
} music_t;

typedef struct s_menu_settings {
    sfbase_t box[2];
    sfbase_t sound[2];
    sfbase_t fps[4];
    unsigned char tmp_fps;
    float tmp_x;
    sfVector2f pos_tmp;
} menu_settings_t;

// btn[0] = play_button
typedef struct s_menu {
    sfbase_t backgrund;
    sfbase_t btn[3];
    music_t music;
    menu_settings_t setting;
} menu_t;

typedef struct s_game_settings {
    sfbase_t box[2];
    sfbase_t sound[2];
    sfbase_t restat;
    sfbase_t man_menu;
} game_settings_t;

typedef struct s_game {
    sfbase_t life[3];
    sfbase_t menu;
    music_t music;
    game_settings_t setting;
} game_t;

// float x;
// float y;
// int top;
// int left;
// int width;
// int height;
typedef struct {
    float x;
    float y;
    int top;
    int left;
    int width;
    int height;
} s;

typedef struct s_text {
    sfText *game_over, *score;
} text_t;

typedef struct s_Keys {
    bool esc;
} KEY_BOOL_t;

typedef struct s_plants_texture {
    sfTexture *z1_alive, *z1_die;
    sfTexture *z2_alive, *z2_die;
    sfTexture *beet_a1, *beet_a2, *beet_a3, *beet_die, *bullet;
    sfTexture *pea_a1, *pea_a2, *pea_a3, *pea_die, *ball;
    sfTexture *walnut_a1, *walnut_a2, *walnut_die;
    sfTexture *flower_alive, *flower_die, *sun;
    sfTexture *mini_map;
} plants_texture_t;

typedef struct s_selected_plant {
    bool *dropped;
    STRUCT_NAME_t name;
    sfSprite *sp;
    sfVector2f pos;
} selected_plant_t;

typedef struct s_mini_map {
    bool dropped;
    sfSprite *sp;
    sfVector2f pos;
} mini_map_t;

typedef struct my_clock_s {
    sfClock *clock1;
    sfTime time;
} my_clock_t;

typedef struct s_sftext {
    sfText *buf;
    sfFont *font;
} sftext_t;

typedef struct s_score {
    unsigned int points;
    sftext_t text;
} score_t;

typedef struct s_win_louse {
    sfbase_t win;
    sfbase_t lose;
    sfbase_t restat;
    sfbase_t man_menu;
    sfbase_t exit;
} win_lose_t;

typedef struct data_s {
    my_clock_t clock;
    unsigned int win_page;
    unsigned int points;
    unsigned int round;
    unsigned int life;
    char *r;
    sfText *text;
    int num;
    sfEvent event;
    sfRenderWindow *window;
    menu_t menu;
    game_t game;
    sftext_t t_round;
    score_t score;
    sfbase_t map;
    sfbase_t mini_map;
    sfbase_t mouse;
    win_lose_t w_l;
    sfbase_t stock[4];
    KEY_BOOL_t key;
    plants_texture_t textures;
    selected_plant_t selected_plant;
    dlist_t *lst, *lst_map, *l_z;
    sfMusic *background_muisc;
    sfFont *font;
    float l;
} data_t;

#endif