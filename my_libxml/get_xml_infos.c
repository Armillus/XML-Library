/*
** EPITECH PROJECT, 2018
** MY_LIBXML
** File description:
** get some infos from a xml file
*/

#include <my_lib_xml.h>

static unsigned int find_first_att_pos(register const char *line)
{
	unsigned int i = 0;

	for (; line[i] && line[i] != SPACE; ++i);
	if (line[i] == '\0' || line[i + 1] == END_TAG ||
	line[i + 1] == CLOSING_TAG)
		return (0);
	return (i);
}

int check_tag_line(char *buffer, size_t counter, unsigned int i)
{
	if (counter == 1) {
		free(buffer);
		return (0);
	} else if (buffer[i - 1] == CLOSING_TAG || buffer[i] == END_TAG)
		i--;
	buffer[i] = '\0';
	return (1);
}

void get_tag_attributes(xml_node_t *node, char *line)
{
	char *buffer = NULL;
	unsigned int i = find_first_att_pos(line);
	size_t counter = 0;

	if (!i)
		return;
	buffer = my_strdup(&line[i + 1]);
	for (i = 0; buffer[i] && buffer[i] != END_TAG; ++i) {
		if (buffer[i] == SPACE && counter == 2) {
			buffer[i] = EQUAL_CHAR;
			counter = 0;
		}
		else if (buffer[i] == ATTR_LIMIT)
			counter++;
	}
	if (!check_tag_line(buffer, counter, i))
		return;
	buffer = my_clean_str(buffer, '\"');
	node->attrs = my_str_to_wordtab(buffer, EQUAL_CHAR);
}

int get_node_infos(xml_node_t *node, register char *line)
{
	unsigned int i = 0;
	register size_t len = my_strlen(line);

	if (len <= 3 || line[len - 1] != END_TAG) {
		my_strerr("Invalid tag : you must create tags according to "\
		"the following pattern : \"<(/)name (attrs)(/)>\".\n");
		return (0);
	}
	if (!check_tag_name(node, line)) {
		for (; line[i] && line[i] != SPACE; ++i);
		line[i] = '\0';
		my_strerr("Error : \"");
		my_strerr(&line[1]);
		my_strerr("\" is an invalid tag name.\n");
		return (0);
	}
	get_tag_attributes(node, line);
	node->is_closed = line[len - 2] == CLOSING_TAG ? TRUE : FALSE;
	return (1);
}
