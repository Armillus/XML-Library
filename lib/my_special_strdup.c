/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** duplicate a single string with a space
*/

#include "shell.h"

char *my_special_strdup(char *src, char c)
{
	char *dest = NULL;
	int i = 0;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(char) * (strlen(my_clean_str(src)) + 2));
	if (!dest)
		return (NULL);
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = c;
	dest[i + 1] = '\0';
	return (dest);
}

char *my_special_strcat(char *str, char *str2, char c)
{
	int i = 0;
	size_t len = 0;
	char *dest = NULL;
	int j = 0;

	if (str == NULL)
		return (my_special_strdup(str2, c));
	len = strlen(str) + strlen(str2) + 1;
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	for (j = 0; str[i] != '\0'; dest[j] = str[i], i++, j++);
	for (i = 0; str2[i] != '\0'; dest[j] = str2[i], i++, j++);
	dest[j] = c;
	free(str);
	return (dest);
}