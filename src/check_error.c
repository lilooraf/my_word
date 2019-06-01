/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** check_error
*/

#include "my.h"

int rules_error(int ac, char **av, int *size_x, int *size_y)
{
    if (ac == 2)
        if (!check_num(av, 1))
            *size_x = *size_y = my_getnbr(av[1]) + 1;
        else
            return 84;
    if (ac > 3) {
        write(2, "Too many arguments.\n", 21);
        return 84;
    }
    if (ac == 3) {
        if (!check_num(av, 1)) {
            *size_x = my_getnbr(av[1]) + 1;
            *size_y = my_getnbr(av[2]) + 1;
        }
        else
            return 84;
    }
    return 0;
}

int check_error(int ac, char **av, int *size_x, int *size_y)
{
    if (usage(ac, av))
        return 1;
    if (rules_error(ac, av, size_x, size_y) == 84)
        return 84;
    if (*size_x > 251 || *size_y > 251 || *size_x <= 1 || *size_y <= 1) {
        write(2, "Out of range.\n", 14);
        return 84;
    }
    return 0;
}