#include <iostream>
#include <cassert>

#include "board.hpp"
#include "tic_tac_toe.hpp"

using namespace std;

int main()
{
  cout << "Starting the tests" << endl;

  Board board;
  Rules *rules = new Rules(&board);
  BoardPrinter *printer = new BoardPrinter(&board);
  TicTacToe *ticTacToe = new TicTacToe(rules, &board, printer);

  assert(ticTacToe->getCurrentMark() == "X");

  ticTacToe->toggleMark();

  assert(ticTacToe->getCurrentMark() == "O");

  ticTacToe->toggleMark();

  assert(ticTacToe->getCurrentMark() == "X");

  cout << "All tests have passed" << endl;
}
