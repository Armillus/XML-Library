/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** cut the first n characters of a string
*/

#include "libmy.h"

char *my_str_ncut(char *str, int n)
{
	if (!str || my_strcmp(str, "") == 0)
		return (NULL);
	for (; str[n]; str += 1) {
		*str = str[n++];
	}
	*str = '\0';
	return (str);
}
