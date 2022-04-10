#include <stdio.h>

int	main(void)
{
	int	arr[] = { 2, 3, 5, 7, 9, 11, 13, 17, 19, 21, 32 };

	for(int i = 0; (unsigned long)i < sizeof(arr) / sizeof(*arr); ++i)
		printf("arr[%d] = %d\n", i, arr[i]);
}
