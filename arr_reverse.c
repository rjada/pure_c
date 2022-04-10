#include <stdio.h>
#include <stdlib.h>

void arr_print(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
		printf("%d%s", arr[i], (i < len - 1) ? ", " : "\n");
}

int	main(int argc, char **argv)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	for (int i = 0; i < argc - 1; ++i)
		arr[i] = atoi(argv[i + 1]);
	arr_print(arr, argc - 1);
	for (int i = 0, j = argc - 2; i < j; i++, j--)
	{
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	arr_print(arr, argc - 1);
	free(arr);
	return (0);
}
