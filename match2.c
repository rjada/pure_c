#include <stdio.h>

int	starmatch(const char *str, const char *pat);

int	match(const char *str, const char *pat)
{
	switch (*pat)
	{
		case 0:
			return (*str == 0);
		case '?':
			if (!*str)
				return (0);
			return (match(str + 1, pat + 1));
		case '*':
			return (starmatch(str, pat + 1));
		default:
			if (*str != *pat)
				return (0);
			return (match(str + 1, pat + 1));
	}
}

int	starmatch(const char *str, const char *pat)
{
	int	i, res;

	for (i = 0; ; ++i)
	{
		if ((res = match(str + i, pat)))
			return (1);
		if (!str[i])
			return (0);
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
