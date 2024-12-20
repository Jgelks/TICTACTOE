#include <cassert>
#include <iostream>

#include "board.hpp"

using namespace std;

int main()
{
  cout << "Running the tests..." << endl;

  Board board;

  board.move(1, "X");
  assert(board.getValue(1) == "X");
  assert(!board.full());

  board.move(2, "O");
  assert(board.getValue(2) == "O");
  assert(!board.full());

  board.move(3, "W");
  assert(board.getValue(3) == "W");
  assert(!board.full());

  // Make sure there are no segmentation faults
  board.move(1000, "X");
  assert(board.getValue(1000) == "");

  // Make sure there are no segmentation faults
  board.move(-1, "X");
  assert(board.getValue(-1) == "");

  board.clear();
  for (int i = 1; i <= 9; i++)
  {
    assert(board.getValue(i) == to_string(i));
  }
  assert(!board.full());

  board.clear();
  for (int i = 1; i <= 9; i++)
  {
    board.move(i, "X");
  }
  assert(board.full());

  cout << "All of the tests have passed!" << endl;
}
