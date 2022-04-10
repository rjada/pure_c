#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	ch;
	int	letter;
	int	space;

	letter = space = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch != '\n')
		{
			if (isspace(ch))
			{
				space++;
				if (letter)
				{
					putchar(')');
					letter = 0;
				}
			}
			else
			{
				letter++;
				if (letter == 1 && !space)
					putchar('(');
				if (space)
				{
					putchar('(');
					space = 0;
				}
			}
			putchar(ch);
		}
		else
		{
			if (letter)
				putchar(')');
			putchar(ch);
			letter = space = 0;
		}
	}
	return (0);
}
