#include <stdio.h>

int	main(int argc, char **argv)
{
	FILE	*from;
	FILE	*to;
	int	c;
	int	line_count;

	if (argc != 3)
	{
		fprintf(stderr, "./fgetputc <file_from> <file_to>\n");
		return (1);
	}
	from = fopen(argv[1], "r");
	if (!from)
	{
		perror(argv[1]);
		return (2);
	}
	to = fopen(argv[2], "w");
	if (!to)
	{
		perror(argv[2]);
		return (3);
	}
	line_count = 0;
	while ((c = fgetc(from)) != EOF)
	{
		fputc(c, to);
		if (c == '\n')
			++line_count;
		if (line_count >= 10)
			break ;
	}
	fclose(from);
	fclose(to);
	return (0);
}
