#include "Hangman.h"

Hangman::Hangman()
{
    for (int i=0; i < MAX_CHARACTERS; i++)
    {
        wordBank[i] = 'z';
        userInput[i] = 'z';
    }
}

Hangman::~Hangman()
{
}

void Hangman::displayHangman()
{
    if (numLives == 6)
    {
        cout << "-- " << " Lives: " << numLives << endl
             << " | " << endl;

    }
    else if (numLives == 5)
    {
        cout << "-- " << " Lives: " << numLives << endl
             << " | " << endl
             << " o " << endl;
    }
    else if (numLives == 4)
    {
        cout << "-- " << " Lives: " << numLives << endl
             << " | " << endl
             << " o " << endl
             << " | " << endl;
    }
    else if (numLives == 3)
    {
        cout << "-- " << " Lives: " << numLives << endl
             << " | " << endl
             << " o " << endl
             << "-| " << endl;
    }
    else if (numLives == 2)
    {
        cout << "-- " << " Lives: " << numLives << endl
             << " | " << endl
             << " o " << endl
             << "-|-" << endl;
    }
    else if (numLives == 1)
    {
        cout << "-- " << " Lives: " << numLives << endl
             << " | " << endl
             << " o " << endl
             << "-|-" << endl
             << "/  " << endl;
    }
    else if (numLives == 0)
    {
        cout << "-- " << " Lives: " << numLives << endl
             << " | " << endl
             << " o " << endl
             << "-|-" << endl
             << "/ \\ " << endl << endl
             << "GAME OVER" << endl;
    }
}


void Hangman::readFile(const string filename)
{
    string wordBankRead[102];
    string word;
    int i = 0;
    
    ifstream infile;
    infile.open(filename.c_str());
     
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            infile >> wordBankRead[i];
            i = i + 1;
        }
        srand (time(NULL));
        i = rand() % 100;
        word = wordBankRead[i];
        n = word.length();
        strcpy(wordBank, word.c_str());
    }
    infile.close();
    for (int z = 0; z < n; z++)
        printArray[z] = '_';
}

//UserInput
void Hangman::userInputs()
{
    char userChar = 'z';
    cout << "Enter a letter" << endl;
    bool valid = false;                          //Go back and do error checking
    cin >> userChar;
    
    for (int i = 0; i < MAX_CHARACTERS; i++)
    {
        userInput[i] = userChar;
        if (userInput[i] == wordBank[i])
        {
            valid = true;
            printWords(i);
        }
    }
    if (valid == false)
        numLives = numLives - 1;
}

//Populating Print Method

void Hangman::printWords(const int i)
{
    printArray[i] = wordBank[i];
}
    
void Hangman::outputWords()
{
    for (int i = 0; i < n; i++)
        cout << printArray[i] << " ";
}

bool Hangman::checkWinning()
{
    bool gameWon = true;
    for (int i = 0; i < n; i++)
    {
        if (printArray[i] == '_' )
            gameWon = false;
    }
    
    if (numLives == 0)
        GAMEOVER = true;
    return(gameWon);
}

void Hangman::playGame()
{   
    char playAgain = 'y';
    while (playAgain == 'y')
    {
        readFile("wordbank.txt");
        while(checkWinning() != true && GAMEOVER == false)
        {
            displayHangman();
            outputWords();
            userInputs();
        }
        if (GAMEOVER == true)
            displayHangman();
        else
            cout << "Congratulations for winning!" << endl;
        
        cout << "Would you like to play again? (y or n)" << endl;
        cin >> playAgain;
        while (playAgain != 'y' && playAgain != 'n')
        {
            cout << "Error... Improper input" << endl
                 << "Would you like to play again? (y or n)" << endl;
            cin >> playAgain;
        }
        if (playAgain == 'y')
        {
	        wordBank[MAX_CHARACTERS];
	        userInput[MAX_CHARACTERS];
	        printArray[MAX_CHARACTERS];
	        numLives = 6;
	        n = 0;
	        GAMEOVER = false;
        }
    }
    cout << "Thank you for playing! Enjoy other games in the arcade too!" << endl;
}
