#include <stdio.h>

void	del_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			j++;
		}	
		i++;
	}
	str[j] = '\0';
}

int	main(void)
{
	char str[50] = "Lol    kek wow      next";
	del_spaces(str);
	printf("%s\n", str);
	return (0);
}
