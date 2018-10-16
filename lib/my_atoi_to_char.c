/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** basic function
*/

int my_atoi_to_char(const char *str, char c)
{
	int b = 0;
	unsigned int count = 0;

	for (; *str && *str != c; str++) {
		if (*str >= '0' && *str <= '9')
			b = b * 10 + (*str - 48);
		else if (*str == '-')
			count++;
	}
	if (count > 0)
		b *= (-1);
	return (b);
}
