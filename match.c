#include <stdio.h>

int	match(const char *str, const char *pat)
{
	int	i;
	for (; ; str++, pat++)
	{
		switch (*pat)
		{
			case 0:
				return (*str == 0);
			case '*':
				for (i = 0; ; ++i)
				{
					if (match(str + i, pat + 1))
						return (1);
					if (!str[i])
						return (0);
				}
			case '?':
				if (!*str)
					return (0);
				break ;
			default:
				if (*str != *pat)
					return (0);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "./match <string> <pattern>\n");
		return (1);
	}
	if (match(argv[1], argv[2]))
		fprintf(stdout, "TRUE\n");
	else
		fprintf(stdout, "FALSE\n");
	return (0);
}
