#include <stdarg.h>
#include <stdio.h>

void	print_times(const char *str, ...)
{
	va_list		vl;
	const char	*p;
	int		i;
	int		n;

	p = str;
	va_start(vl, str);
	while (p)
	{
		n = va_arg(vl, int);
		i = 0;
		while (i < n)
		{
			printf("%s ", p);
			i++;
		}
		printf("\n");
		p = va_arg(vl, const char *);
	}
	va_end(vl);
	//printf("##\n");
}

int	main(void)
{
	print_times("OK", 5, "KO", 10, "lol", 15, "wow", 20);
}
