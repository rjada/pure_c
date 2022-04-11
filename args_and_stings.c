#include <stdio.h>

unsigned	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p)
		p++;
	return (p - str);
}

int	is_letter(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

void	print_max(int argc, char **argv)
{
	int	i;
	int	current_len;
	int	max_len;
	int	max_index;

	max_len = 0;
	i = 1;
	while (i < argc)
	{
		current_len = ft_strlen(argv[i]);
		if (max_len < current_len)
		{
			max_len = current_len;
			max_index = i;
		}
		i++;
	}
	printf("%s [%d]\n", argv[max_index], max_len);
}

int	are_repeat_letters(const char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (!is_letter(str[i]))
		{
			i++;
			continue ;
		}
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_no_repeat_letters(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!are_repeat_letters(argv[i]))
			printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
}

void	print_dog_dot(int argc, char **argv)
{
	int	i;
	int	j;
	int	dog;
	int	dot;

	i = 1;
	while (i < argc)
	{
		j = dog = dot = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '@')
				dog++;
			if (argv[i][j] == '.')
				dot++;
			j++;
		}
		if (dog == 1 && dot)
			printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
}

void	print_only_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (i < argc)
	{
		j = 0;
		flag = 1;
		while (argv[i][j])
		{
			if (!is_digit(argv[i][j]))
				flag = 0;
			j++;
		}
		if (flag)
			printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
}

void	print_only_same_char(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (i < argc)
	{
		j = 1;
		flag = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != argv[i][0])
				flag = 0;
			j++;
		}
		if (flag)
			printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Enter some arguments.\n");
		return (1);
	}
	print_max(argc, argv);
	print_no_repeat_letters(argc, argv);
	print_dog_dot(argc, argv);
	print_only_digits(argc, argv);
	print_only_same_char(argc, argv);
	return (0);
}
