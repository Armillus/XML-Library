/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** basic function
*/

#include "libmy/libmy.h"

int my_str_isnum(const char *str)
{
	while (*str) {
		if (!IS_DIGIT(*str) && *str != '-')
			return (0);
		str += 1;
	}
	return (1);
}
