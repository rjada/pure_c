#include <stdio.h>

int	main(void)
{
	char	str[7];

	fgets(str, 6, stdin);
	str[5] = '\n';
	str[6] = 0;
	fputs(str, stdout);
}
