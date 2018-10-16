/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** my_pokemon
*/

#include "libmy/libmy.h"

char *my_strcat_char(char *str, char c)
{
	size_t len = my_strlen(str);
	char *new_str = malloc(sizeof(char *) * (len + 2));

	my_strcpy(new_str, str);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	return (new_str);
}
