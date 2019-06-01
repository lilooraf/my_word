/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** change_map
*/

#include "my.h"

void rules_mouse(st_t *st, bt_t **bt, int x, int y)
{
    if (((st->pm2.x >= (int)st->map_2d[x][y].x - 7) &&
    (st->pm2.x <= (int)st->map_2d[x][y].x + 7)) &&
    ((st->pm2.y >= (int)st->map_2d[x][y].y - 7) &&
    (st->pm2.y <= (int)st->map_2d[x][y].y + 7))) {
        st->point.x = x;
        st->point.y = y;
        st->boul = 1;
    }
}

void hight_mouse(int ***map, st_t *st, bt_t **bt)
{
    int i = st->size_x;
    int j = st->size_y;

    if (st->p_or_s) {
        i -= 1;
        j -= 1;
    }
    for (int x = 0; x < i; x++)
        for (int y = 0; y < j; y++)
            rules_mouse(st, bt, x, y);
}

int calc_hight(st_t *st)
{
    float sint = sin(20 * M_PI / 180);
    int y = sint * (st->point.y * st->size + st->m.y);
    int x = sint * (st->point.x * st->size);
    int m = st->pm2.y - 150;

    return ((y + x - m) / (st->size * 0.07));
}

void hight_change(int ***map, st_t *st, bt_t **bt)
{
    int z = calc_hight(st);

    if (st->mouse == 1 && st->boul == 0)
        hight_mouse(map, st, bt);
    if (st->mouse == 1 && st->boul && !st->p_or_s && st->point.x != -1)
        map[0][st->point.x][st->point.y] = calc_hight(st);
    if (st->mouse == 1 && st->boul && st->p_or_s && st->point.x != -1) {
        z = calc_hight(st);
        map[0][st->point.x + 1][st->point.y + 1] = z;
        map[0][st->point.x][st->point.y + 1] = z;
        map[0][st->point.x + 1][st->point.y] = z;
        map[0][st->point.x][st->point.y] = z;
    }
}

void change_map_size(int ***map, st_t *st, bt_t **bt)
{
    for (int i = 0; i < 11; i++)
        if (bt[0][i].status)
            st->all = 0;
    if (st->select && st->all)
        hight_change(map, st, bt);
    if (bt[0][5].status && st->b == 1)
        map_plus_x(map, &st->size_x, &st->size_y, st);
    if (bt[0][6].status && st->b == 1)
        map_minus_x(map, &st->size_x, &st->size_y, st);
    if (bt[0][3].status && st->b == 1)
        map_plus_y(map, &st->size_x, &st->size_y, st);
    if (bt[0][4].status && st->b == 1)
        map_minus_y(map, &st->size_x, &st->size_y, st);
    if (sfKeyboard_isKeyPressed(sfKeyR) || bt[0][11].status) {
        free(*map);
        *map = create_map(st->base_x, st->base_y);
        st->size_y = st->base_y;
        st->size_x = st->base_x;
    }
    if (st->event.type == sfEvtMouseButtonReleased && st->b == 0)
        st->b = 1;
}