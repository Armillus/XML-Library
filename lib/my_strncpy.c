/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** basic function
*/

#include "libmy.h"

char *my_strncpy(char *str, int n)
{
	if (!str || n >= my_strlen(str))
		return (str);
	str[n] = '\0';
	return (str);
}
