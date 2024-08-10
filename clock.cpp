#include "clock.h"
#include <iostream>

Clock::Clock()
{
  update();
}

void Clock::update()
{
  char _time[7];
  char _date[32];
  std::time_t clock = std::time(nullptr);
  std::strftime(_time, sizeof(_time), "%H%M%S", std::localtime(&clock));
  std::strftime(_date, sizeof(_date), "%A, %d %B %Y", std::localtime(&clock));

  time = _time;
  hours = time.substr(0, 2);
  minutes = time.substr(2, 2);
  seconds = time.substr(4, 2);
  date = _date;
}

void Clock::printTime()
{
  std::cout << getHours() << ':' << getMinutes() << ':' << getSeconds() << '\n' << getDate() << '\n';
}

string Clock::getTime()
{
  return time;
}

string Clock::getFormattedTime()
{
  string formatted = getHours() + ':' + getMinutes() + ':' + getSeconds();
  return formatted;
}

string Clock::getHours()
{
  return hours;
}

string Clock::getMinutes()
{
  return minutes;
}

string Clock::getSeconds()
{
  return seconds;
}

string Clock::getDate()
{
  return date;
}
