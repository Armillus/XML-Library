/*
** EPITECH PROJECT, 2018
** LIBMY
** File description:
** strcmp function
*/

int my_strcmp(const char *src, const char *str)
{
	while (*src && *src == *str) {
		src += 1;
		str += 1;
	}
	return (*src - *str);
}
