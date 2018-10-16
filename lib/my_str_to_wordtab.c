/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** basic function to split a string
*/

#include "libmy/libmy.h"

char **my_str_to_wordtab(char *str, char c)
{
	char **tab = NULL;
	uint j = 0;
	uint nb_words = 0;

	if (!str)
		return (NULL);
	tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
	if (!tab)
		return (NULL);
	for (uint i = 0; str[i]; ++i) {
		if (str[i] == c && str[i + 1]) {
			str[i++] = '\0';
			tab[nb_words++] = &str[j];
			j = i;
		}
	}
	tab[nb_words] = &str[j];
	tab[++nb_words] = NULL;
	return (tab);
}