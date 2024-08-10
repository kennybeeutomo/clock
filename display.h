#pragma once
#include "clock.h"
#include "number.h"

class Display
{
public:
  Display(Clock* _clock, short _size, short _color);
  void updateNumbers();
  void display(bool _refresh = false) const;
  void centerPosition();
  void changePosition(short _x, short _y);

  void increaseSizeBy(short _size);
  void increaseSpaceSizeBy(short _spaceSize);
  void nextColor();
  void prevColor();

private:
  Clock* clock;
  short x;
  short y;
  short size;
  short spaceSize;
  short color;

  short maxX;
  short maxY;
  short totalNumbersWidth;
  short totalNumbersHeight;
  std::array <std::pair<Number, short>, 8> numbers;
};
