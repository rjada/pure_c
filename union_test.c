#include <stdio.h>

typedef union	split_int
{
	int		integer;
	unsigned char	bytes[sizeof(int)];
}		split_int_t;

int	main(void)
{
	split_int_t	si;

	printf("Please enter an integer number: ");
	scanf("%d", &si.integer);
	for (int i = 0; i < (int)sizeof(int); ++i)
		printf("byte #%d is %02x\n", i, si.bytes[i]);
}
