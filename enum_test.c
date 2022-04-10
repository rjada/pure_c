#include <stdio.h>

enum	{ false_ft, true_ft };
enum	colors
{
	red	= 0xff0000,
	green	= 0x00ff00,
	blue	= 0x0000ff,
	cyan	= 0xffff00,
	magenta	= 0xff00ff,
	black	= 0xffffff,
	white	= 0x000000
};

void	print_color(enum colors col)
{
	switch (col)
	{
		case red:
			printf("red\n");
			break;
		case green:
			printf("green\n");
			break;
		case blue:
			printf("blue\n");
			break;
		case cyan:
			printf("cyan\n");
			break;
		case magenta:
			printf("magenta\n");
			break;
		case black:
			printf("black\n");
			break;
		case white:
			printf("white\n");
			break;
	}
}

int	main(void)
{
	printf("%d %d\n", false_ft, true_ft);
	printf("%d %d %d\n", red, green >> 8, blue);
	print_color(black);
	return (0);
}
