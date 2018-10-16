/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** basic function
*/

#include "libmy/libmy.h"

char *my_strncpy(char *str, size_t n)
{
	if (!str || n >= my_strlen(str))
		return (str);
	str[n] = '\0';
	return (str);
}
