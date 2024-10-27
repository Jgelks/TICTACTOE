#include <iostream>
#include <cassert>

#include "board.hpp"
#include "board_printer.hpp"

using namespace std;

int main()
{
  cout << "Running the tests..." << endl;

  Board board;
  BoardPrinter *boardPrinter = new BoardPrinter(&board);

  assert(boardPrinter->print() == " 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

  board.move(1, "X");
  assert(boardPrinter->print() == " X | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

  board.move(2, "O");
  assert(boardPrinter->print() == " X | O | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

  board.move(3, "W");
  assert(boardPrinter->print() == " X | O | W \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 ");

  board.move(4, "V");
  assert(boardPrinter->print() == " X | O | W \n-----------\n V | 5 | 6 \n-----------\n 7 | 8 | 9 ");

  board.move(5, "P");
  assert(boardPrinter->print() == " X | O | W \n-----------\n V | P | 6 \n-----------\n 7 | 8 | 9 ");

  board.move(6, "L");
  assert(boardPrinter->print() == " X | O | W \n-----------\n V | P | L \n-----------\n 7 | 8 | 9 ");

  board.move(7, "M");
  assert(boardPrinter->print() == " X | O | W \n-----------\n V | P | L \n-----------\n M | 8 | 9 ");

  board.move(8, "H");
  assert(boardPrinter->print() == " X | O | W \n-----------\n V | P | L \n-----------\n M | H | 9 ");

  board.move(9, "F");
  assert(boardPrinter->print() == " X | O | W \n-----------\n V | P | L \n-----------\n M | H | F ");

  cout << "All of the tests have passed!" << endl;
}
