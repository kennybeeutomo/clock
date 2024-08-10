#include "clock.h"
#include "curses.h"
#include "display.h"

int main(int argc, char** argv)
{
  initscr();
  noecho();
  nodelay(stdscr, true);
  keypad(stdscr, true);

  if (!has_colors()) exit(1);
  start_color();
  for (int i = 0; i < 8; ++i)
    init_pair(i, i, i);
  
  Clock clock;
  Display display(&clock, 4, COLOR_RED);
  display.increaseSpaceSizeBy(-2);

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
      case 'm':
        display.increaseSpaceSizeBy(-1);
        break;
      case ',':
        display.increaseSpaceSizeBy(1);
        break;
      case 'i':
        display.prevColor();
        break;
      case 'o':
        display.nextColor();
        break;
      case 'c':
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
    napms(16);
  }

  endwin();
}
