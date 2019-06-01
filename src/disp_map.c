/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** disp_map
*/

#include "my.h"

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfBlue};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

sfVertexArray *dis_line(sfVector2f *a, sfVector2f *b, sfRenderWindow *window)
{
    sfVertexArray *array;

    array = create_line(a, b);
    sfRenderWindow_drawVertexArray(window, array, NULL);
    sfVertexArray_destroy(array);
}

void set_button(st_t *st, bt_t **bt)
{
    if (bt[0][9].status)
        st->p_or_s = 1;
    if (bt[0][10].status)
        st->p_or_s = 0;
    if (bt[0][7].status)
        st->select = 1;
    if (bt[0][8].status)
        st->select = 0;
    if (bt[0][0].status == 1)
        st->size += 1;
    if (bt[0][1].status == 1 && st->size > 10)
        st->size -= 1;
    st->all = 1;
}

void create_array(st_t *st, bt_t **bt)
{
    sfVertexArray *array;

    for (int x = 0; x < st->size_x; x++) {
        for (int y = 0; y < st->size_y; y++) {
            (y + 1 < st->size_y) ? dis_line(&st->map_2d[x][y],
            &st->map_2d[x][y + 1], st->wi) : 0;
            (x + 1 < st->size_x) ? dis_line(&st->map_2d[x][y],
            &st->map_2d[x + 1][y], st->wi) : 0;
        }
    }
    set_button(st, bt);
}

sfVector2f project_iso_point(float x, float y, float z, st_t *st)
{
    static sfVector2f point;
    float sint = sin(20 * M_PI / 180);
    float cost = cos(45 * M_PI / 180);

    point.x = cost * (x + st->m.x) - cost * y + 800;
    point.y = sint * (y + st->m.y) + sint * x - z + 150;
    return (point);
}