/*
** EPITECH PROJECT, 2018
** MY_LIBXML
** File description:
** check tags and attributes of a xml file
*/

#include "my_lib_xml.h"

size_t search_in_tree(xml_node_t *tree, char *tag, size_t nb)
{
	if (my_strcmp(tree->name, tag) == 0)
		nb++;
	if (tree->next)
		nb = search_in_tree(tree->next, tag, nb);
	if (tree->child)
		nb = search_in_tree(tree->child, tag, nb);
	return (nb);
}

xml_node_t *display_invalid_file(xml_node_t *node, const char *filename)
{
	if (node)
		free(node);
	my_strerr("Error : \"");
	my_strerr(filename);
	my_strerr("\" does not exist.\n");
	return (NULL);
}

int check_tag_name(xml_node_t *node, char *line)
{
	int pos = -1;
	unsigned int i = 1;

	for (; line[i]; ++i) {
		if (line[i] == SPACE || line[i] == CLOSING_TAG ||
		line[i] == END_TAG)
			break;
		for (int k = 0; VALID_CHARS[k]; ++k)
			pos = VALID_CHARS[k] == line[i] ? k : pos;
		if (pos == -1)
			return (0);
	}
	node->name = my_strndup(&line[1], i - 1);
	return (1);
}

int check_closing_tag(xml_node_t *node, char *line)
{
	unsigned int i = 0;

	for (; line[i] && line[i] != END_TAG; ++i);
	if (line[i] == '\0') {
		my_strerr("Invalid tag : you must create tags according to "\
		"the following pattern : \"<(/)name (attrs)(/)>\".\n");
		return (0);
	}
	line[i] = '\0';
	if (my_strcmp(&line[2], node->name) != 0) {
		my_strerr("\"");
		my_strerr(&line[2]);
		my_strerr("\" is an invalid tag name.\n");
		return (0);
	} else
		node->is_closed = TRUE;
	return (1);
}

