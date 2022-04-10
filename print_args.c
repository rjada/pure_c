#include <stdio.h>

int	is_minus(const char *str)
{
	while (*str)
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!is_minus(argv[i]))
			puts(argv[i]);
		i++;
	}
	return (0);
}
