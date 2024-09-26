#pragma once
#ifndef BOARD_HPP
#define BOARD_HPP
#endif

#include <string>

using namespace std;

class Board
{
private:
  string marks[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

public:
  void move(int index, string mark);
  string getValue(int index);
  void clear();
};
