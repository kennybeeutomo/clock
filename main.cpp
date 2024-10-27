#include "clock.hpp"
#include "curses.h"
#include "display.hpp"
#include <string>

#include "config.cpp"

void initColors() {
	if (!has_colors()) exit(1);
	start_color();
	for (int i = 0; i < 8; ++i)
		init_pair(i, i, 0);
//		          n  f  g
}

void cursesConfig() {
	noecho();
	nodelay(stdscr, true);
	keypad(stdscr, true);
}

int main(int argc, char** argv)
{
	initscr();
	cursesConfig();
	initColors();

	Clock clock;
	Display display(&clock, SIZE, COLOR);
	display.setSpaceSize(SPACESIZE);

	bool running = true;
	while (running)
	{
		switch (getch())
		{
			case 'j':
				display.increaseSizeBy(-1);
				break;
			case 'k':
				display.increaseSizeBy(1);
				break;
			case 'J':
				display.increaseSpaceSizeBy(-1);
				break;
			case 'K':
				display.increaseSpaceSizeBy(1);
				break;
			case 'p':
				display.prevColor();
				break;
			case 'n':
				display.nextColor();
				break;
			case 'q':
				running = false;
				break;
			case KEY_RESIZE:
				if (is_termresized()) resize_term(0, 0);
				break;
			default:
				break;
		}
		display.centerPosition();
		display.updateNumbers();
		display.display(true);
		napms(36);
	}

	endwin();
}
