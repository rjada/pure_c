#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int x, y, res;

	printf("Enter two integers: ");
	res = scanf("%d %d", &x, &y);
	if (res != 2)
	{
		printf("Error.\n");
		return (1);
	}
	printf("x = %d, y = %d\nMake swap...\n", x, y);	
	swap(&x, &y);
	printf("x = %d, y = %d\n", x, y);
	return (0);
}
