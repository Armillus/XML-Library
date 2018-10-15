/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** Basic function to write on stderr
*/

#include "libmy.h"

inline void my_strerr(const char *str)
{
	if (str)
		write(2, str, my_strlen(str));
}
