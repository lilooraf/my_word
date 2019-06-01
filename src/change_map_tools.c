/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** change_map_tools
*/

#include "my.h"

void map_plus_y(int ***map_old, int *size_x, int *size_y, st_t *st)
{
    int **map = NULL;

    if (*size_y >= 250)
        return;
    *size_y += 1;
    map = my_calloc(sizeof(int *), (*size_x));
    for (int x = 0; x < *size_x; x++)
        map[x] = my_calloc(sizeof(int), (*size_y));
    for (int x = 0; x < *size_x; x++) {
        for (int y = 0; y < *size_y - 2; y++)
            map[x][y] = map_old[0][x][y];
    }
    for (int x = 0; x < *size_x; x++)
        map[x][*size_y - 2] = 0;
    free(map_old[0]);
    map_old[0] = map;
    st->b = 0;
}

void map_plus_x(int ***map_old, int *size_x, int *size_y, st_t *st)
{
    int **map = NULL;

    if (*size_x >= 250)
        return;
    *size_x += 1;
    map = my_calloc(sizeof(int *), (*size_x));
    for (int x = 0; x < *size_x; x++)
        map[x] = my_calloc(sizeof(int), (*size_y));
    for (int x = 0; x < *size_x - 2; x++) {
        for (int y = 0; y < *size_y; y++)
            map[x][y] = map_old[0][x][y];
    }
    for (int y = 0; y < *size_y; y++)
        map[*size_x - 2][y] = 0;
    free(map_old[0]);
    map_old[0] = map;
    st->b = 0;
}

void map_minus_y(int ***map_old, int *size_x, int *size_y, st_t *st)
{
    int **map = NULL;

    if (*size_y <= 2)
        return;
    *size_y -= 1;
    map = malloc(sizeof(int *)* (*size_x));
    for (int x = 0; x < *size_x; x++)
        map[x] = malloc(sizeof(int)* (*size_y));
    for (int x = 0; x < *size_x; x++) {
        for (int y = 0; y < *size_y - 2; y++)
            map[x][y] = map_old[0][x][y];
    }
    st->b = 0;
}

void map_minus_x(int ***map_old, int *size_x, int *size_y, st_t *st)
{
    int **map = NULL;

    if (*size_x <= 2)
        return;
    *size_x -= 1;
    map = malloc(sizeof(int *)* (*size_x));
    for (int x = 0; x < *size_x; x++)
        map[x] = malloc(sizeof(int)* (*size_y));
    for (int x = 0; x < *size_x; x++) {
        for (int y = 0; y < *size_y; y++)
            map[x][y] = map_old[0][x][y];
    }
    st->b = 0;
}