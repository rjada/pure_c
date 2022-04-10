#include <stdio.h>
#include <stdlib.h>

static void	solve(int src, int dst, int tmp, int n)
{
	if (n == 0)
		return ;
	solve(src, tmp, dst, n - 1);
	printf("%d: %d -> %d\n", n, src, dst);
	solve(tmp, dst, src, n - 1);
}

int	main(int argc, char **argv)
{
	int	n;

	if (argc != 2)
	{
		fprintf(stderr, "./hanoi <positive number of rings>\n");
		return (1);
	}
	n = atoi(argv[1]);
	if (n < 1)
	{
		fprintf(stderr, "Incorrect token count\n");
		return (2);
	}
	solve(1, 3, 2, n);
	return (0);
}
