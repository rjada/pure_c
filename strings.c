#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	const char *p;

	p = str;
	while (*p)
		p++;
	return (p - str);
}

void	ft_strcpy(char *dest, const char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

int	main(void)
{
	char	*src = "Hello, world!"; 
	char	*dest;

	printf("%d\n", ft_strlen(src));
	dest = (char *)malloc(ft_strlen(src) + 1);
	ft_strcpy(dest, src);
	printf("%s\n", dest);
	free(dest);
}
