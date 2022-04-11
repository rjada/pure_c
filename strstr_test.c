#include <stdio.h>

unsigned	ft_strlen(const char *str)
{
	const char *p;

	p = str;
	while (*p)
		p++;
	return (p - str);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	if (!needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return ((void *)0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	count_occur;
	char	*buf;

	if (argc < 2)
	{
		fprintf(stderr, "Enter The arguments.\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		count_occur = 0;
		buf = argv[i];
		while ((buf = ft_strstr(buf, argv[1])) != NULL)
		{
			count_occur++;
			buf += ft_strlen(argv[1]);
		}
		if (count_occur)
			printf("%s [%d]\n", argv[i], count_occur);
		i++;
	}
	return (0);
}
