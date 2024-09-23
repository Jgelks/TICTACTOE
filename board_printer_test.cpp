#include <cassert>

#include "board.hpp"
#include "board_printer.hpp"

int main() {
    Board board;
    BoardPrinter *boardPrinter = new BoardPrinter(&board);

    assert(boardPrinter->print() == " 1 | 2 | 3 \n-----------\n   |   |   \n-----------\n   |   |   ");

    board.move(1, "X");
    assert(boardPrinter->print() == " X | 2 | 3 \n-----------\n   |   |   \n-----------\n   |   |   ");

    board.move(2, "O");
    assert(boardPrinter->print() == " X | O | 3 \n-----------\n   |   |   \n-----------\n   |   |   ");

    board.move(3, "W");
    assert(boardPrinter->print() == " X | O | W \n-----------\n   |   |   \n-----------\n   |   |   ");
}