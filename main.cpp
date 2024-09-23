#include <iostream>

#include "board.hpp"
#include "rules.hpp"
#include "game.hpp"
#include "board_printer.hpp"

using namespace std;

int main() {
    Board board;
    Rules *rules = new Rules(&board);
    BoardPrinter *boardPrinter = new BoardPrinter(&board);
    Game *game = new Game(rules, &board, boardPrinter);
    
    game->start();
}