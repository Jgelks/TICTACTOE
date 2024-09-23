#include <cassert>
#include <iostream>

#include "board.hpp"
#include "rules.hpp"

using namespace std;

int main() {
    cout << "Starting the tests" << endl;

    Board board;
    Rules *rules = new Rules(&board);

    assert(rules->inProgress());

    board.move(1, "X");
    assert(rules->inProgress());

    board.move(2, "X");
    assert(rules->inProgress());

    board.move(3, "X");
    assert(!rules->inProgress());

    board.clear();

    board.move(1, "O");
    assert(rules->inProgress());

    board.move(2, "O");
    assert(rules->inProgress());

    board.move(3, "O");
    assert(!rules->inProgress());

    board.clear();

    board.move(1, "F");
    assert(rules->inProgress());
    assert(rules->status() == "");

    board.move(4, "F");
    assert(rules->inProgress());
    assert(rules->status() == "");

    board.move(7, "F");
    assert(!rules->inProgress());
    assert(rules->status() == "F");

    board.clear();

    board.move(2, "P");
    assert(rules->inProgress());

    board.move(5, "P");
    assert(rules->inProgress());

    board.move(8, "P");
    assert(!rules->inProgress());

    cout << "All of the tests passed!" << endl;
}