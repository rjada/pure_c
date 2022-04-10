#include <stdio.h>

int	get_and_zero(int *num)
{
	int res = *num;
	*num = 0;
	return (res);
}

int	put_sum(int *a, int *b, int *c)
{
	int res = *a + *b + *c;
	*a = *b = *c = res;
	return (res);
}

int	main(void)
{
	int num = 42;
	int a = 2;
	int b = 3;
	int c = 5;

	printf("num (before) = %d\n", num);
	printf("f(num) = %d\n", get_and_zero(&num));
	printf("num (after) = %d\n", num);
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("sum = %d\n", put_sum(&a, &b, &c)
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	return (0);
}
