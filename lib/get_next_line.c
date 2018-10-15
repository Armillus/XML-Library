/*
** EPITECH PROJECT, 2018
** main function
** File description:
** get_next_line
*/

#include "get_next_line.h"

static int my_strnlen(const char *str, register int option)
{
	register int i = 0;

	for (; str[i]; ++i) {
		if (option != 0 && str[i] == '\n')
			return (i + 1);
		else if (option == -2 && str[i] != '\n' && !str[i + 1])
			return (0);
	}
	return (option == -1 ? 0 : i);
}

static char *my_str_ncpy(char *str, int p)
{
	if (!str)
		return (NULL);
	if (p == -2) {
		for (; *str && *str != '\n'; str += 1);
		*str = '\0';
	}
	return (str);
}

char *my_strcat(char *src, const char *str)
{
	register char *dest = NULL;

	if (!src)
		return (my_strdup(str));
	dest = malloc(sizeof(char) * (strlen(src) + strlen(str) + 1));
	if (!dest)
		return (NULL);
	for (size_t i = 0; src[i]; ++i)
		*dest++ = src[i];
	while (*str)
		*dest++ = *str++;
	*dest = '\0';
	free(src);
	return (dest);
}

static char *my_str_nsuppr(char *str)
{
	unsigned int i = 0;
	int j = 0;

	if (my_strnlen(str, -1) == 0 && strlen(str) > 0) {
		free(str);
		return (NULL);
	}
	for (j = my_strnlen(str, -2); str[j + i]; ++i)
		str[i] = str[j + i];
	str[i] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	static char *s = NULL;
	char b[READ_SIZE + 1] = {0};
	ssize_t ctr = 1;

	if (fd == -1 || READ_SIZE <= 0)
		return (NULL);
	if (!s && (ctr = read(fd, b, READ_SIZE))) {
		b[ctr] = '\0';
		s = my_strdup(b);
	} else if (s && (my_strnlen(s, -1) || strlen(s) >= 1))
		s = my_str_nsuppr(s);
	while (s && !my_strnlen(s, -1) && (ctr = read(fd, b, READ_SIZE))) {
		b[ctr] = '\0';
		s = my_strcat(s, b);
	}
	if (!s || (ctr <= 0 && strlen(s) < 1)) {
		if (s)
			free(s);
		s = NULL;
	}
	return (s ? my_str_ncpy(my_strdup(s), -2) : NULL);
}
