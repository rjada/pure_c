#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int	main(void)
{
	int	ch;
	int	letter;
	int	space;
	int	word;
	int	odd;
	int	even;
	int	le2;
	int	mt7;
	int	max_w;
	int	min_w;
	int	max_sp;

	letter = space = word = odd = even = le2 = mt7 = max_w = max_sp = 0;
	min_w = INT_MAX;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
		{
			if (!word && letter)
				word++;
			if (letter)
			{
				if (letter % 2 == 0)
					even++;
				else
					odd++;
			}
			if (letter && (letter > 7))
				mt7++;
			if (letter && (letter <= 2))
				le2++;
			if (!word)
				min_w = 0;
			if (letter && max_w < letter)
				max_w = letter;
			if (letter && min_w > letter)
				min_w = letter;
			if (space && space > max_sp)
				max_sp = space;
			printf("%d\n", word);
			printf("%d %d\n", even, odd);
			printf("%d %d\n", mt7, le2);
			printf("%d %d %d\n", word, max_w, min_w);
			printf("%d %d\n", max_w, max_sp);
			word = letter = space = odd = even = le2 = mt7 = max_w = max_sp = 0;
			min_w = INT_MAX;
		}
		else
		{
			if (isspace(ch))
			{
				space++;
				if (letter)
				{
					if (!word)
						word++;
					if (letter % 2 == 0)
						even++;
					else
						odd++;
					if (letter > 7)
						mt7++;
					if (letter <= 2)
						le2++;
					if (max_w < letter)
						max_w = letter;
					if (min_w > letter)
						min_w = letter;
					letter = 0;
				}
			}
			if (!isspace(ch))
			{
				letter++;
				if (space)
				{
					word++;
					if (max_sp < space)
						max_sp = space;
					space = 0;
				}
			}
		}
	}
	return (0);
}
