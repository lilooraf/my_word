/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** my_world
*/

#include "my.h"

void mouse(st_t *st, int *b, sfEvent event)
{
    static sfVector2i tmp;

    if (event.type == sfEvtMouseButtonPressed && *b == 0)
        if (event.mouseButton.button == sfMouseLeft) {
            tmp = sfMouse_getPositionRenderWindow(st->wi);
            *b = 1;
        }
    if (event.type == sfEvtMouseButtonReleased) {
        tmp.x = 0;
        tmp.y = 0;
        st->tmp2.x = st->m.x;
        st->tmp2.y = st->m.y;
        *b = 0;
        st->boul = 0;
    }
    if (*b == 1 && st->select == 0) {
        st->m.x = (st->pm2.x - tmp.x) + st->tmp2.x;
        st->m.y = (st->pm2.y - tmp.y) + st->tmp2.y;
    }
    st->mouse = *b;
}

void event(st_t *st)
{
    sfEvent event;
    static int b = 0;

    while (sfRenderWindow_pollEvent(st->wi, &event)) {
        st->event = event;
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(st->wi);
        st->pm2 = sfMouse_getPositionRenderWindow(st->wi);
        if (event.type == sfEvtMouseButtonPressed)
            st->pm = sfMouse_getPositionRenderWindow(st->wi);
        else {
            st->pm.x = 0;
            st->pm.y = 0;
        }
        if (event.type == sfEvtMouseWheelScrolled)
            st->scroll = event.mouseWheelScroll.delta;
        mouse(st, &b, event);
    }
}

st_t init_st(int size_x, int size_y)
{
    st_t st;
    sfVideoMode mode = {1600, 900, 32};

    st.size = 2000 / (size_y + size_x);
    st.b = 1;
    st.select = 1;
    st.tmp2.x = 0;
    st.tmp2.y = 0;
    st.p_or_s = 0;
    st.point.x = -1;
    st.point.y = -1;
    st.base_x = st.size_x = size_x;
    st.base_y = st.size_y = size_y;
    st.scroll = 0;
    st.wi = NULL;
    st.m.x = 0;
    st.m.y = 0;
    st.wi = sfRenderWindow_create(mode, "My_World", sfTitlebar | sfClose, NULL);
    return (st);
}

void display(int size_x, int size_y)
{
    st_t st = init_st(size_x, size_y);
    bt_t *bt = init_struct();
    int **map = create_map(size_x, size_y);
    sfTexture *te_bg;
    sfSprite *sf_bg = print_img("src/img/background/bg.png", &te_bg, sf_bg);

    sfRenderWindow_setFramerateLimit(st.wi, 60);
    while (sfRenderWindow_isOpen(st.wi) && !bt[2].status) {
        event(&st);
        sfRenderWindow_clear(st.wi, sfBlack);
        sfRenderWindow_drawSprite(st.wi, sf_bg, NULL);
        create_2d_map(map, &st);
        create_array(&st, &bt);
        change_map_size(&map, &st, &bt);
        for (int i = 0; i <= 11; i++)
            set_bt(&bt[i], st.wi, &st.pm, &st.pm2);
        sfRenderWindow_display(st.wi);
    }
    sfTexture_destroy(te_bg);
    sfSprite_destroy(sf_bg);
    sfRenderWindow_destroy(st.wi);
}