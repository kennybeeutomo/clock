#include "pixel.h"
#include "curses.h"
#include <iostream>

Pixel::Pixel()
: x(0), y(0), size(0), active(false), color(0)
{ }

Pixel::Pixel(short _x, short _y, short _size, bool _active, short _color)
: x(_x), y(_y), size(_size), active(_active), color(_color)
{ }

void Pixel::display(bool _refresh) const
{
  for (short Y = y; Y < y + size/2; Y++)
    for (short X = x; X < x + size; X++)
    {
      if (active)
        mvaddch(Y, X, ' ' | COLOR_PAIR(color));
      else
        mvaddch(Y, X, ' ' | COLOR_PAIR(COLOR_BLACK));
    }
  if (_refresh) refresh();
}

void Pixel::changePosition(short _x, short _y)
{
  x = _x;
  y = _y;
}

void Pixel::changeSize(short _size)
{
  size = _size;
}

void Pixel::changeActivation(bool _active)
{
  active = _active;
}

void Pixel::changeColor(short _color)
{
  color = _color;
}
