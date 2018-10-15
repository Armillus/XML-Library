/*
** EPITECH PROJECT, 2018
** LIBMY
** File description:
** Prototypes and macros for libmy
*/

#ifndef LIBMY_LIBMY_H
#define LIBMY_LIBMY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define IS_WHITESPACE(c) ((c) && ((c) == ' ' || (c) == '\t' || \
(c) == '\r' || (c) == '\f' || (c) == '\v') ? 1 : 0)

#define IS_DIGIT(c) ((c) && (c) >= '0' && (c) <= '9' ? (1) : (0))

typedef unsigned int uint;

char *my_strncpy(char *str, int n);
char *my_clean_str(char *str, char c);
void my_putchar(char c);
size_t my_strlen(const char *str);
inline void my_putstr(const char *str);
int my_str_isnum(const char *str);
char **my_str_to_wordtab(char *str, char c);
char *my_strdup(const char *str);
inline void my_strerr(const char *str);
char *my_str_ncut(char *str, int n);
int my_strcmp(const char *src, const char *str);

#endif //LIBMY_LIBMY_H
