#include <stdio.h>

void	print_next_number()
{
	static int	n;
	printf("%d\n", n++);
}

int	main(void)
{
	for (int i = 0; i < 10; ++i)
		print_next_number();
	return (0);
}
