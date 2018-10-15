/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** basic function to duplicate a string
*/

#include "libmy.h"

char *my_strdup(const char *str)
{
	char *dest = NULL;

	if (!str)
		return (NULL);
	dest = malloc(sizeof(char) * (my_strlen(str) + 1));
	if (!dest)
		return (NULL);
	for (; *str;)
		*dest++ = *str++;
	*dest = '\0';
	return (dest);
}