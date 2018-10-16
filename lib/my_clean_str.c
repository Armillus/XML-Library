/*
** EPITECH PROJECT, 2018
** my_clean_str
** File description:
** main function
*/

#include "libmy/libmy.h"

char *my_clean_str(char *str, char c)
{
	size_t idx = 0;

	if (!str)
		return (NULL);
	for (size_t i = 0; str[i]; ++i) {
		if (IS_WHITESPACE(str[i]) && idx != 0 &&
		!IS_WHITESPACE(str[i + 1])) {
			str[idx++] = ' ';
		} else if (str[i] != c && !IS_WHITESPACE(str[i])) {
			str[idx++] = str[i];
		}
	}
	str[idx] = '\0';
	return (str);
}
