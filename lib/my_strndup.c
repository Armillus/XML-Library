/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** basic function
*/

#include "libmy/libmy.h"

char *my_strndup(const char *src, unsigned int n)
{
	char *dest = NULL;
	unsigned int i = 0;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	for (i = 0; src[i] && i < n; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
