#include "board.hpp"

void Board::move(int index, string mark)
{
  if (index > 0 && index < 10)
  {
    this->marks[index - 1] = mark;
  }
}

string Board::getValue(int index)
{
  if (index > 0 && index < 10)
  {
    return this->marks[index - 1];
  }
  else
  {
    return "";
  }
}

void Board::clear() {
  for(int i = 0; i < 9; i++) {
    this->marks[i] = to_string(i + 1);
  }
}
