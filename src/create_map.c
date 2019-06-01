/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** create_map
*/

#include "my.h"

int **create_map(int size_x, int size_y)
{
    int **map = NULL;

    map = malloc(sizeof(int *) * (size_x));
    for (int x = 0; x < size_x; x++) {
        map[x] = malloc(sizeof(int) * (size_y));
        for (int y = 0; y < size_y; y++)
            map[x][y] = 0;
    }
    return (map);
}

void create_2d_map(int **map, st_t *st)
{
    sfVector2f **map_2d;
    float cood_x = 0;
    float cood_y = 0;
    float cood_z = 0;

    st->size = (st->size <= 4 && st->scroll < 0) ?
    4 : st->size + (st->scroll / 0.9);
    map_2d = malloc(sizeof(sfVector2f *) * (st->size_x));
    for (int x = 0; x < st->size_x; x++) {
        map_2d[x] = malloc(sizeof(sfVector2f) * (st->size_y));
        for (int y = 0; y < st->size_y; y++) {
            cood_x = x * st->size;
            cood_y = y * st->size;
            cood_z = map[x][y] * st->size * 0.07;
            map_2d[x][y] = project_iso_point(cood_x, cood_y, cood_z, st);
        }
    }
    st->scroll = 0;
    st->map_2d = map_2d;
}