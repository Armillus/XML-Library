/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** Print string
*/

#include "my_lib_xml.h"

int my_strerr(const char *str)
{
	return ((int)write(2, str, my_strlen(str)));
}
