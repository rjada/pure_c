#include <stdio.h>

void	string5(FILE *f1, FILE *f2)
{
	char	buf[6];
	int	null_pos;
	int	c;

	while (fgets(buf, sizeof(buf), f1))
	{
		null_pos = -1;
		for (int i = 0; i < (int)sizeof(buf) && buf[i]; ++i)
			if (buf[i] == '\n')
			{
				null_pos = i;
				break ;
			}
		if (null_pos == -1)
		{
			fputc('\n', f2);
			while ((c = fgetc(f1)) != EOF)
				if (c == '\n')
					break ;
		}
		else			
		{
			buf[null_pos] = '\0';
			fprintf(f2, "[%s]\n", buf);
		}
	}
}

int	main(void)
{
	string5(stdin, stdout);
	return (0);
}
