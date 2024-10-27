#include "display.hpp"
#include "curses.h"
#include "number.hpp"

Display::Display(Clock* _clock, short _size, short _color)
: clock(_clock), size(_size), spaceSize(_size), color(_color)
{
	for (size_t i = 0; i < numbers.size(); i++)
		numbers.at(i).second = i;
}

void Display::updateNumbers() {
	clock->update();
	for (auto& numberPair : numbers)
	{
		Number& number = numberPair.first;
		short& index = numberPair.second;

		short clockNum = clock->getFormattedTime().at(index) - 48;

		number.changePosition(x + index*size*3 + spaceSize*index, y);
		number.changeSize(size);
		number.changeNum(clockNum);
		number.changeColor(color);
		number.updatePixels();
	}
}

void Display::display(bool _refresh) const {
	erase();
	for (const auto& number : numbers) {
		number.first.display();
	}
	string date = clock->getDate();
	mvprintw(maxY/2 + totalNumbersWidth/2 + 4, maxX/2 - date.length(), "%s", date.c_str());
	if (_refresh) refresh();
}

void Display::centerPosition() {
	getmaxyx(stdscr, maxY, maxX);
	short midX = maxX/2;
	short midY = maxY/2;
	totalNumbersWidth = 8*size*3 + 7*spaceSize;
	totalNumbersHeight = size*5/2;
	changePosition(midX - totalNumbersWidth/2, midY - totalNumbersHeight/2);
	updateNumbers();
}

void Display::changePosition(short _x, short _y) {
	x = _x;
	y = _y;
}

void Display::increaseSizeBy(short _size) {
	if (size + _size > 1) size = size + _size;
}

void Display::increaseSpaceSizeBy(short _spaceSize) {
	if (spaceSize + _spaceSize > 0) spaceSize = spaceSize + _spaceSize;
}

void Display::setSize(short _size) {
	size = _size;
}

void Display::setSpaceSize(short _spaceSize) {
	if (spaceSize < 1) {
		spaceSize = _spaceSize;
	} else {
		spaceSize = 1;
	}
}

void Display::nextColor() {
	if (color + 1 < 8) ++color;
	else color = 1;
}

void Display::prevColor() {
	if (color - 1 > 0) --color;
	else color = 7;
}
