/*
** EPITECH PROJECT, 2018
** MY_LIB_XML
** File description:
** list of structures and prototypes for the lib
*/

#ifndef MY_LIB_XML_H_
#define MY_LIB_XML_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "basic_fn/get_next_line.h"

#define TRUE 1
#define FALSE 0

#define SPACE ' '
#define EQUAL_CHAR '='
#define ATTR_LIMIT '"'
#define OPENING_TAG '<'
#define CLOSING_TAG '/'
#define END_TAG '>'

#define VALID_CHARS "abcdefghijklmnopqrstuvwxyz1234567890-_"

typedef struct xml_node_s {
	char **attrs;
	struct xml_node_s *parent;
	struct xml_node_s *child;
	struct xml_node_s *next;
	char *data;
	char *name;
	char is_closed;
} xml_node_t;

char *get_next_line(int fd);
void print_my_tab(char **tab);
size_t search_in_tree(xml_node_t *tree, char *tag, size_t nb);
xml_node_t *display_invalid_file(xml_node_t *node, const char *filename);
char *my_strcat_char(char *str, const char *str2, char c);
int get_node_infos(xml_node_t *node, register char *line);
void get_tag_attributes(xml_node_t *node, char *line);
int check_tag_name(xml_node_t *node, register char *line);
int check_closing_tag(xml_node_t *node, register char *line);
void free_xml_tree(xml_node_t *tree);
xml_node_t *parse_xml_file(register const char *filename);
int my_strerr(const char *str);
char **my_str_to_wordtab(char *str, char c);
char *my_clean_str(char *str, char c);
int my_strcmp(char const *s1, char const *s2);
size_t my_strlen(char const *str);
char *my_strndup(const char *src, unsigned int n);

#endif
