#pragma once
#include <curses.h>

#include "config.cpp"

class Pixel
{
public:
	Pixel();
	Pixel(short _x, short _y, short _size, bool _active, short _color);
	void display(bool _refresh = false) const;

	void changePosition(short _x, short _y);
	void changeSize(short _size);
	void changeActivation(bool _active);
	void changeColor(short _color);

private:
	short x;
	short y;
	short size;
	bool active;
	short color;
};
