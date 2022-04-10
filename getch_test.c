#include <stdio.h>

int	main(void)
{
	int	c;

	while((c = getchar()) != EOF)
	{
		if (c == '\n')
			printf("OK\n");
	}
	return (0);
}
