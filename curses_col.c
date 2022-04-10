#include <stdio.h>
#include <curses.h>

enum			{ key_escape = 27 };
enum			{ color_count = 8 };
static const int	all_colors[color_count] =
{
	COLOR_BLACK, COLOR_RED, COLOR_GREEN, COLOR_YELLOW,
	COLOR_BLUE, COLOR_MAGENTA, COLOR_CYAN, COLOR_WHITE
};

static int	setpair(int fg, int bg)
{
	int	n;

	n = bg * 8 + fg + 1;
	init_pair(n, fg, bg);
	return (n);
}

static void	make_line(int line, int width, int fgcolor)
{
	int	w;
	int	pn;
	int	att;

	w = width / color_count;
	for (int i = 0; i < color_count; i++)
	{
		move(line, i * w);
		pn = setpair(fgcolor, all_colors[i]);
		for (int j = 0; j < w; j++)
		{
			att = COLOR_PAIR(pn);
			if (j % 2 == 0)
				att |= A_BOLD;
			if ((j / 2) % 2 == 1)
				att |= A_BLINK;
			attrset(att);
			addch('*');
			refresh();
		}
	}
}

static void	make_skreen(int h, int w)
{
	clear();
	for (int i = 0; i < h; i++)
		make_line(i, w, all_colors[i % color_count]);
}

static void	shift_pairs(int shift)
{
	for (int i = 0; i <= color_count * color_count; i++)
	{
		int fg = (i + shift) % color_count;
		int bg = ((i + shift) / color_count) % color_count;
		init_pair(i, fg, bg);
	}
}

int	main(void)
{
	int	row;
	int	col;
	int	ch;
	int	shift;

	initscr();
	if (!has_colors())
	{
		endwin();
		fprintf(stderr, "I cant't show colors on a BW screen\n");
		return (1);
	}
	cbreak();
	keypad(stdscr, 1);
	noecho();
	curs_set(0);
	start_color();
	getmaxyx(stdscr, row, col);
	make_skreen(row, col);
	shift = 2;
	while ((ch = getch()) != key_escape)
	{
		shift_pairs(shift);
		shift++;
		refresh();
	}
	endwin();
	return (0);
}
