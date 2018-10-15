/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** basic function to write one character
*/

#include "libmy.h"

void my_putchar(const char c)
{
	write(1, &c, 1);
}
