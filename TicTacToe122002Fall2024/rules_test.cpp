#include <cassert>
#include <iostream>

#include "board.hpp"
#include "rules.hpp"

using namespace std;

int main()
{
  cout << "Starting the tests" << endl;

  Board board;
  Rules *rules = new Rules(&board);

  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(1, "X");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(2, "X");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(3, "X");
  assert(!rules->inProgress());
  assert(rules->status() == "X wins the game!");

  board.clear();

  board.move(4, "O");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(5, "O");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(6, "O");
  assert(!rules->inProgress());
  assert(rules->status() == "O wins the game!");

  board.clear();
  assert(rules->inProgress());

  board.move(7, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(8, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(9, "H");
  assert(!rules->inProgress());
  assert(rules->status() == "H wins the game!");

  board.clear();
  assert(rules->inProgress());

  board.move(1, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(4, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(7, "H");
  assert(!rules->inProgress());
  assert(rules->status() == "H wins the game!");

  board.clear();
  assert(rules->inProgress());

  board.move(2, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(5, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(8, "H");
  assert(!rules->inProgress());
  assert(rules->status() == "H wins the game!");

  board.clear();
  assert(rules->inProgress());

  board.move(3, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(6, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(9, "H");
  assert(!rules->inProgress());
  assert(rules->status() == "H wins the game!");

  board.clear();
  assert(rules->inProgress());

  board.move(1, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(5, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(9, "H");
  assert(!rules->inProgress());
  assert(rules->status() == "H wins the game!");

  board.clear();
  assert(rules->inProgress());

  board.move(3, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(5, "H");
  assert(rules->inProgress());
  assert(rules->status() == "");

  board.move(7, "H");
  assert(!rules->inProgress());
  assert(rules->status() == "H wins the game!");

  board.move(1, "A");
  board.move(2, "B");
  board.move(3, "C");
  board.move(4, "D");
  board.move(5, "E");
  board.move(6, "F");
  board.move(7, "G");
  board.move(8, "H");
  board.move(9, "I");
  assert(!rules->inProgress());
  assert(rules->status() == "Tie game!");

  cout << "All of the tests passed!" << endl;
}
