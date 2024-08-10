#pragma once
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::string;

class Clock
{
public:
  Clock();
  void update();
  void printTime();
  string getTime();
  string getFormattedTime();
  string getHours();
  string getMinutes();
  string getSeconds();
  string getDate();

private:
  string hours;
  string minutes;
  string seconds;
  string time;
  string date;
};
