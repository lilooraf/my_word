/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct bt
{
    sfTexture *tex_bt;
    sfSprite *sp_bt;
    sfTexture *tex_bt1;
    sfSprite *sp_bt1;
    sfTexture *tex_bt2;
    sfSprite *sp_bt2;
    int x;
    int y;
    int size_x;
    int size_y;
    int status;
}bt_t;

typedef struct st
{
    sfVector2i point;
    sfVector2i tmp2;
    int all;
    int select;
    int boul;
    int mouse;
    int size;
    int b;
    int scroll;
    int p_or_s;
    int size_x;
    int size_y;
    int base_x;
    int base_y;
    sfEvent event;
    sfVector2i m;
    sfVector2i pm;
    sfVector2i pm2;
    sfVector2f **map_2d;
    sfRenderWindow *wi;
}st_t;

#endif
