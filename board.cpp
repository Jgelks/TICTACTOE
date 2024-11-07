#include "board.hpp"
#include <iostream>
#include "battle_tic_tac_toe.hpp"
extern string playerOneMark;
extern string playerTwoMark;

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

void Board::clear()
{
  for (int i = 0; i < 9; i++)
  {
    this->marks[i] = to_string(i + 1);
  }
}

bool Board::full()
{
  for (int i = 0; i < 9; i++)
  {
    if (this->marks[i] == to_string(i + 1))
    {
      return false;
    }
  }
  return true;
}

void Board::alchemistAbility(string mark)
{
  int indexOfYourMark;
  int indexOfOpponentsMark;
  string indexOfOpponentsMarkString;
  bool yourMarkValid = false;
  bool opponentsMarkValid = false;
  while (!yourMarkValid)
  {
    cout << "Select which of your marks you want to transmute!" << endl;
    cin >> indexOfYourMark;
    if (marks[indexOfYourMark - 1] == mark)
    {
      yourMarkValid = true;
    }
    else
    {
      cout << "That is not your mark!" << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  while (!opponentsMarkValid)
  {
    cout << "Select which of your opponents marks to transmute it with!" << endl;
    cin >> indexOfOpponentsMark;
    indexOfOpponentsMarkString = indexOfOpponentsMark;

    if (indexOfOpponentsMarkString.size() == 1 && marks[indexOfOpponentsMark - 1] != mark && marks[indexOfOpponentsMark - 1] != "1" && marks[indexOfOpponentsMark - 1] != "2" && marks[indexOfOpponentsMark - 1] != "3" && marks[indexOfOpponentsMark - 1] != "4" && marks[indexOfOpponentsMark - 1] != "5" && marks[indexOfOpponentsMark - 1] != "6" && marks[indexOfOpponentsMark - 1] != "7" && marks[indexOfOpponentsMark - 1] != "8" && marks[indexOfOpponentsMark - 1] != "9" && indexOfOpponentsMarkString != "0")
    {
      opponentsMarkValid = true;
    }
    else
    {
      cout << "That is not your opponents mark!" << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  this->marks[indexOfYourMark - 1] = this->marks[indexOfOpponentsMark - 1];
  this->marks[indexOfOpponentsMark - 1] = mark;
}

void Board::paladinAbility()
{
  int indexOfMarkToBeBlessed;
  int indexToMoveTo;
  bool thisMarkValid = false;
  bool isValidIndexToMoveTo = false;
  while (!thisMarkValid)
  {
    cout << "Select which mark you wish to bless!" << endl;
    cin >> indexOfMarkToBeBlessed;
    if (marks[indexOfMarkToBeBlessed - 1] == playerOneMark || marks[indexOfMarkToBeBlessed - 1] == playerTwoMark)
    {
      thisMarkValid = true;
    }
    else
    {
      cout << "That is not a valid mark!" << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  while (!isValidIndexToMoveTo)
  {
    cout << "Select which index you would like to move the blessed mark" << endl;
    cin >> indexToMoveTo;
    // All of these "if" statements just check to make sure
    // the player is moving to a valid empty index based on the orignal
    // index of the mark
    if (marks[indexToMoveTo - 1] == playerOneMark || marks[indexToMoveTo - 1] == playerTwoMark)
    {
      cout << "You may only move to an empty index!" << endl;
    }
    if (indexOfMarkToBeBlessed == 1 && (indexToMoveTo != 2 && indexToMoveTo != 4 && indexToMoveTo != 5))
    {
      cout << "You may only move to an adjacent index!" << endl;
    }
    else if (indexOfMarkToBeBlessed == 2 && (indexToMoveTo != 1 && indexToMoveTo != 3 && indexToMoveTo != 4 && indexToMoveTo != 5 && indexToMoveTo != 6))
    {
      cout << "You may only move to an adjacent index!" << endl;
    }
    else if (indexOfMarkToBeBlessed == 3 && (indexToMoveTo != 2 && indexToMoveTo != 5 && indexToMoveTo != 6))
    {
      cout << "You may only move to an adjacent index!" << endl;
    }
    else if (indexOfMarkToBeBlessed == 4 && (indexToMoveTo != 1 && indexToMoveTo != 2 && indexToMoveTo != 5 && indexToMoveTo != 7 && indexToMoveTo != 8))
    {
      cout << "You may only move to an adjacent index!" << endl;
    }
    else if (indexOfMarkToBeBlessed == 5 && indexToMoveTo == 5)
    {
      cout << "You may only move to an adjacent index!" << endl;
    }
    else if (indexOfMarkToBeBlessed == 6 && (indexToMoveTo != 3 && indexToMoveTo != 2 && indexToMoveTo != 5 && indexToMoveTo != 8 && indexToMoveTo != 9))
    {
      cout << "You may only move to an adjacent index!" << endl;
    }
    else if (indexOfMarkToBeBlessed == 7 && (indexToMoveTo != 4 && indexToMoveTo != 5 && indexToMoveTo != 8))
    {
      cout << "You may only move to an adjacent index!" << endl;
    }
    else if (indexOfMarkToBeBlessed == 8 && (indexToMoveTo != 4 && indexToMoveTo != 5 && indexToMoveTo != 6 && indexToMoveTo != 7 && indexToMoveTo != 9))
    {
      cout << "You may only move to an adjacent index!" << endl;
    }
    else if (indexOfMarkToBeBlessed == 9 && (indexToMoveTo != 5 && indexToMoveTo != 6 && indexToMoveTo != 8))
    {
      cout << "You may only move to an adjacent index!" << endl;
    }
    else{
      isValidIndexToMoveTo = true;
    }
  }
  this->marks[indexToMoveTo - 1] = this->marks[indexOfMarkToBeBlessed - 1];
  this->marks[indexOfMarkToBeBlessed - 1] = to_string(indexOfMarkToBeBlessed);

}

void Board::ballistaAbility(){
int indexToStartBallista;
int directionChoice;
cout << "Please enter the index at which you would like the start your ballista! (1, 2, 3, 4, or 7)" << endl;
cin >> indexToStartBallista;
if(indexToStartBallista == 1 ){
  cout << "Would you like to launch your ballista to 3 or 7?" << endl;
  cin >> directionChoice;
  if (directionChoice == 3){
    for(int i = 0; i < 3; i++){
    this->marks[indexToStartBallista - 1 + i] = to_string(i + indexToStartBallista);
  }
  }
  else if (directionChoice == 7){
    for(int i = 0; i < 7; i = i + 3){
    this->marks[indexToStartBallista - 1 + i] = to_string(i + indexToStartBallista);
  }
  }
}
if(indexToStartBallista == 2 || indexToStartBallista == 3){
  for(int i = 0; i < 7; i = i + 3){
    this->marks[indexToStartBallista - 1 + i] = to_string(i + indexToStartBallista);
  }
}
if(indexToStartBallista == 4 || indexToStartBallista == 7){
  for(int i = 0; i < 3; i++){
    this->marks[indexToStartBallista - 1 + i] = to_string(i + indexToStartBallista);
  }
}


}
