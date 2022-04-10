#include <stdio.h>

int	main(void)
{
	int	c;
	int	flag;

	flag = 1;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			putchar('\n');
			flag = 1;
			continue;
		}
		else if (c == ' ')
		{
			flag = 0;
			continue;
		}
		else
			if (flag)
				putchar(c);
	}
	printf("%#x\n", 255);
}
