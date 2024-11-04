#include <sstream>

#include "board_printer.hpp"

BoardPrinter::BoardPrinter(Board *board) {
    this->board = board;
}

string BoardPrinter::print() {
    stringstream ss;
  
	ss << this->edgeSpace;
	for(int i = 1; i <= 8; i++)
	{
       ss << board->getValue(i);
       if(i%3 == 0)
       {
    		ss  << this->edgeSpace
				<< this->horizontalDivider
				<< this->edgeSpace;
   		}
   		else
    		ss << this->verticalDivider;
	}
	ss << board->getValue(9);
	ss << this->edgeSpace;
	
    return ss.str();
}
