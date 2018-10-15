/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** basic function to write on standard output
*/

#include "libmy.h"

inline void my_putstr(const char *str)
{
	if (str)
		write(1, str, my_strlen(str));
}
