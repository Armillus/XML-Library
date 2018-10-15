/*
** EPITECH PROJECT, 2018
** my_clean_str
** File description:
** main function
*/

#include "libmy.h"

char *my_clean_str(char *str, char c)
{
	size_t idx = 0;

	if (!str)
		return (NULL);
	for (; *str; str += 1) {
		if (IS_WHITESPACE(*str) && idx != 0 &&
		IS_WHITESPACE(*str + 1)) {
			str[idx++] = ' ';
		} else if (*str != c)
			str[idx++] = *str;
	}
	str[idx] = '\0';
	return (str);
}
