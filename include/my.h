/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <stdlib.h>
#include <math.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct.h"
#include <unistd.h>

void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_str_isalpha(char const *str);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_str_isprintable(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *);
int my_putstrn(char const *);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_putnbr_base(int nb, char const *base);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char const *src);
void *my_calloc(size_t elem_size, size_t elems);
char **my_str_to_word_array(char *str);
char **my_str_to_word_array_char(char *str, char c);
char *my_clear_str(char *str);
int check_num(char **av, int start);
int usage(int ac, char **av);
char *strcpy_end(char *dest, char *src);
bt_t *init_struct(void);
void set_bt(bt_t *bt, sfRenderWindow *wi, sfVector2i *pm, sfVector2i *pm2);
sfVector2f vec(float x, float y);
sfSprite *print_img(const char *, sfTexture **, sfSprite *);
void display(int size_x, int size_y);
void change_map_size(int ***map, st_t *st, bt_t **bt);
int **create_map(int size_x, int size_y);
void map_minus_x(int ***map_old, int *size_x, int *size_y, st_t *st);
void map_minus_y(int ***map_old, int *size_x, int *size_y, st_t *st);
void map_plus_x(int ***map_old, int *size_x, int *size_y, st_t *st);
void map_plus_y(int ***map_old, int *size_x, int *size_y, st_t *st);
void hight_change(int ***map, st_t *st, bt_t **bt);
void create_2d_map(int **map, st_t *st);
sfVector2f project_iso_point(float x, float y, float z, st_t *st);
void create_array(st_t *st, bt_t **bt);
sfVertexArray *dis_line(sfVector2f *a, sfVector2f *b, sfRenderWindow *window);
sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2);
void event(st_t *st);
void mouse(st_t *st, int *b, sfEvent event);
void display(int size_x, int size_y);
char **open_map(char *str);
int **comvert_char_int(char **tab, int *x, int *y);
sfMusic* music_p(char *str);
void hight_mouse(int ***map, st_t *st, bt_t **bt);
int check_error(int ac, char **av, int *size_x, int *size_y);

#endif