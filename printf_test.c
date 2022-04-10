#include <stdio.h>

int	main(void)
{
	int	i = 493;
	char	*str = "Hello";

	printf("%d:%6d:%-6d:%06d:%7.5d:%x:%X\n", i, i, i, i, i, i, i);
	printf("#%3s#\n", str);
	printf("#%8s#\n", str);
	printf("#%-8s#\n", str);
	printf("#%3.4s#\n", str);
	printf("#%6.4s#\n", str);
}
