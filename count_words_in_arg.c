#include <stdio.h>

int	words_count(const char *str)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str && *str != ' ')
		{
			words++;
			while (*str && *str != ' ')
				str++;
		}
	}
	return (words);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Input one argument with many words in parantheses.\n");
		return (1);
	}
	printf("You enter %d words in argument.\n", words_count(argv[1]));
	return (0);
}
