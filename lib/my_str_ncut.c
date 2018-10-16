/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** cut the first n characters of a string
*/

#include "libmy/libmy.h"

char *my_str_ncut(char *str, int n)
{
	if (IS_NULL_OR_EMPTY(str))
		return (NULL);
	for (; str[n]; str += 1) {
		*str = str[n++];
	}
	*str = '\0';
	return (str);
}
