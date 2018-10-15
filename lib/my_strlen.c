/*
** EPITECH PROJECT, 2018
** LIBMY
** File description:
** strlen function
*/

size_t my_strlen(const char *str)
{
	size_t i = 0;

	for (; str[i++];);
	return (i);
}