/*
** EPITECH PROJECT, 2018
** MY_LIB_XML
** File description:
** parse a xml file
*/

#include "my_lib_xml.h"

static xml_node_t *init_xml_node(xml_node_t *parent_node)
{
	xml_node_t *node = malloc(sizeof(xml_node_t));

	if (!node)
		return (NULL);
	node->parent = parent_node;
	node->child = NULL;
	node->next = NULL;
	node->attrs = NULL;
	node->data = NULL;
	node->name = NULL;
	node->is_closed = FALSE;
	return (node);
}

void free_xml_tree(xml_node_t *tree)
{
	if (tree->attrs) {
		for (int i = 0; tree->attrs[i]; ++i)
			free(tree->attrs[i]);
		free(tree->attrs);
	}
	if (tree->data)
		free(tree->data);
	if (tree->name)
		free(tree->name);
	if (tree->next)
		free_xml_tree(tree->next);
	if (tree->child)
		free_xml_tree(tree->child);
	free(tree);
}

static xml_node_t *create_new_node(xml_node_t *current_node,
unsigned int nb_line)
{
	if (nb_line != 0 && current_node->name && !current_node->child &&
	current_node->is_closed == FALSE) {
		current_node->child = init_xml_node(current_node);
		current_node = current_node->child;
	} else if (nb_line != 0 && current_node->name) {
		current_node = current_node->child;
		while (current_node->next)
			current_node = current_node->next;
		current_node->next = init_xml_node(current_node->parent);
		current_node = current_node->next;
	}
	return (current_node);
}

static int analyze_new_line(xml_node_t *node,
register char *line, unsigned int nb_lines)
{
	static xml_node_t *cur_node = NULL;

	cur_node = !cur_node || nb_lines == 0 ? node : cur_node;
	if (line[0] != OPENING_TAG) {
		if (nb_lines == 0) {
			my_strerr("You can't begin a file without a tag.\n");
			return (0);
		}
		cur_node->data = my_strcat_char(cur_node->data, line, '\n');
	} else if (line[0] == OPENING_TAG && line[1] == CLOSING_TAG) {
		if (nb_lines == 0 || !check_closing_tag(cur_node, line))
			return (0);
	} else {
		cur_node = create_new_node(cur_node, nb_lines);
		if (!get_node_infos(cur_node, line))
			return (0);
	}
	cur_node->is_closed == TRUE ? cur_node = cur_node->parent : 0;
	return (1);
}

xml_node_t *parse_xml_file(register const char *filename)
{
	xml_node_t *node = init_xml_node(NULL);
	FILE *stream = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int nb_lines = 0;

	if (!node || !(stream = fopen(filename, "r")))
		return (display_invalid_file(node, filename));
	while (getline(&line, &len, stream) != -1) {
		line[strlen(line) - 1] = '\0';
		if (!analyze_new_line(node, my_clean_str(line, 0), nb_lines)) {
			free_xml_tree(node);
			node = NULL;
			break;
		}
		nb_lines++;
	}
	free(line);
	fclose(stream);
	return (node);
}