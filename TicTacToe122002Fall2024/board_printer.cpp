#include <sstream>

#include "board_printer.hpp"

BoardPrinter::BoardPrinter(Board *board) {
    this->board = board;
}

string BoardPrinter::print() {
    stringstream ss;
    ss << this->edgeSpace
       << board->getValue(1)
       << this->verticalDivider
       << board->getValue(2)
       << this->verticalDivider
       << board->getValue(3)
       << this->edgeSpace
       << this->horizontalDivider
       << this->edgeSpace
       << board->getValue(4)
       << this->verticalDivider
       << board->getValue(5)
       << this->verticalDivider
       << board->getValue(6)
       << this->edgeSpace
       << this->horizontalDivider
       << this->edgeSpace
       << board->getValue(7)
       << this->verticalDivider
       << board->getValue(8)
       << this->verticalDivider
       << board->getValue(9)
       << this->edgeSpace;
    return ss.str();
}