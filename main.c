/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    sfMusic* music = NULL;
    int size_x = 11;
    int size_y = 11;
    int error = check_error(ac, av, &size_x, &size_y);

    if (error == 1)
        return 0;
    if (error == 84)
        return 84;
    display(size_x, size_y);
    return 0;
}