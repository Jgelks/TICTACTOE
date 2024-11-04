#pragma once

#include "board.hpp"

class BoardPrinter
{
private:
  Board *board;
  string edgeSpace = " ";
  string horizontalDivider = "\n-----------\n";
  string verticalDivider = " | ";

public:
  BoardPrinter(Board *board);
  string print();
};
