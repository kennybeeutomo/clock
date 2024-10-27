#pragma once
#include "pixel.hpp"
#include <array>

#include "config.cpp"

class Number
{
public:
	Number();
	Number(short _x, short _y, short _size, short _num, short _color);

	void updatePixels();
	void display(bool _refresh = false) const;

	void changePosition(short _x, short _y);
	void changeSize(short _size);
	void changeNum(short _num);
	void changeColor(short _color);

private:
	short x;
	short y;
	short size;
	short num;
	short color;

	std::array <Pixel, 3*5> pixels;
	bool numMap[11][5][3] = {
		{
			{1,1,1},
			{1,0,1},
			{1,0,1},
			{1,0,1},
			{1,1,1},
		},
		{
			{0,0,1},
			{0,0,1},
			{0,0,1},
			{0,0,1},
			{0,0,1},
		},
		{
			{1,1,1},
			{0,0,1},
			{1,1,1},
			{1,0,0},
			{1,1,1},
		},
		{
			{1,1,1},
			{0,0,1},
			{1,1,1},
			{0,0,1},
			{1,1,1},
		},
		{
			{1,0,1},
			{1,0,1},
			{1,1,1},
			{0,0,1},
			{0,0,1},
		},
		{
			{1,1,1},
			{1,0,0},
			{1,1,1},
			{0,0,1},
			{1,1,1},
		},
		{
			{1,1,1},
			{1,0,0},
			{1,1,1},
			{1,0,1},
			{1,1,1},
		},
		{
			{1,1,1},
			{0,0,1},
			{0,0,1},
			{0,0,1},
			{0,0,1},
		},
		{
			{1,1,1},
			{1,0,1},
			{1,1,1},
			{1,0,1},
			{1,1,1},
		},
		{
			{1,1,1},
			{1,0,1},
			{1,1,1},
			{0,0,1},
			{1,1,1},
		},
		{
			{0,0,0},
			{0,1,0},
			{0,0,0},
			{0,1,0},
			{0,0,0},
		},

	};
};
