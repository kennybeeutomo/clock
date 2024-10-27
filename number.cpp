#include "number.hpp"
#include "curses.h"

Number::Number()
: x(0), y(0), size(0), num(0)
{ }

Number::Number( short _x, short _y, short _size, short _num, short _color)
: x(_x), y(_y), size(_size), num(_num), color(_color)
{
	updatePixels();
}

void Number::updatePixels()
{
	for (short i = 0; i < 3*5; ++i)
	{
		Pixel& pixel = pixels.at(i);

		short X = i%3;
		short Y = i/3;

		pixel.changePosition(x + X*size, y + Y*(size/2));
		pixel.changeSize(size);
		pixel.changeActivation(numMap[num][Y][X]);
		pixel.changeColor(color);
	}
}

void Number::display(bool _refresh) const
{
	for (const Pixel& pixel : pixels)
	pixel.display();
	if (_refresh) refresh();
}

void Number::changePosition(short _x, short _y)
{
	x = _x;
	y = _y;
}

void Number::changeSize(short _size)
{
	size = _size;
}

void Number::changeNum(short _num)
{
	num = _num;
}

void Number::changeColor(short _color)
{
	color = _color;
}
