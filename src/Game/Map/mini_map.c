/*
** EPITECH PROJECT, 2020
** .my_defender (Workspace)
** File description:
** mini_map
*/

#include <my_tools.h>
#include <my_printf.h>
#include <my_defender.h>

mini_map_t *creat_mini_map_node(int x, int y, plants_texture_t texture)
{
    mini_map_t *mini_map = malloc(sizeof(mini_map_t));
    mini_map->dropped = false;
    mini_map->sp = sfSprite_create();
    sfSprite_setTexture(mini_map->sp, texture.mini_map, sfTrue);
    mini_map->pos = (sfVector2f){15.0 * x, 15.0 * y};
    mini_map->dropped = false;
    sfSprite_setPosition(mini_map->sp, mini_map->pos);
    return mini_map;
}

void creat_mini_map(data_t *src, char *map)
{
    int x = 0, y = 0, end = 0;
    src->lst_map = NULL;
    #define IS_OBSTACL(c) (c == 'm')
    for (int i = 0; map[i] != '\0'; i++, x++) {
        if (map[i] == 'E') {
            end = x;
            y = 0;
        } else if (map[i] == '\n') {
            x = -1;
            y++;
        }
        if (IS_OBSTACL(map[i]))
            push_back(&src->lst_map,
                creat_mini_map_node(x + end, y, src->textures), S_MINI_MAP);
    }
}

int open_map(data_t *src, char const *file, void(creat_src)(data_t *, char *))
{
    int fd = 0;
    ssize_t ssize = 0;
    char buf[6400], *map = NULL;

    if ((fd = open(file, O_RDONLY)) <= -1) {
        my_printf("ERROR: can't open \"%s\" file\n", file);
        return 84;
    } else {
        while ((ssize = read(fd, buf, 6400)), ssize != -1, ssize != 0) {
            buf[ssize] = '\0';
            map = my_strncdup(map, buf, ssize);
        }
        if (ssize  <= -1) {
            my_printf("ERROR: can't read \"%s\" file\n", file);
            return 84;
        }
        creat_src(src, map);
        free(map);
        close(fd);
    }
}