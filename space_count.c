#include <stdio.h>

int	count_spaces(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == ' ')
			count++;
		str++;
	}
	return (count);
}

int	count_spaces_rec(const char *str)
{
	int	count;
	if (!str)
		return (-1);
	count = 0;
	if (*str == '\0')
		return (count);
	else if (*str == ' ')
		count++;
	return (count + count_spaces_rec(str + 1));
}

int	main(void)
{
	int	n;

	n = count_spaces("lol kek wow next best");
	printf("%d\n", n);
	n = count_spaces(NULL);
	printf("%d\n", n);
	n = count_spaces_rec("lol kek wow next best");
	printf("%d\n", n);
	n = count_spaces_rec(NULL);
	printf("%d\n", n);
	return (0);
}
