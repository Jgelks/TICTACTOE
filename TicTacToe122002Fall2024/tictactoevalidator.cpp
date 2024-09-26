while (!valid)
{
    cin >> userInput;
    if (userInput > 9 || userInput < 1)
    {
        cout << "That is out of range!\n";
    }

    else if (board->getValue(userInput) == "X" || board->getValue(userInput) == "O")
    {
        cout << "That space is already taken!\n";
    }

    else
    {
        break;
    }
}

bool validator(&userInput)
{

    cin >> userInput;
    if(userinput.size() > 1){
        cout << "Your input must be a single digit integer.\n";

    }
    if (userInput > 9 || userInput < 1)
    {
        cout << "That is out of range!\n";
    }

    else if (board->getValue(userInput) == "X" || board->getValue(userInput) == "O")
    {
        cout << "That space is already taken!\n";
    }

    else
    {
        return false;
    }
}