#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

class Hangman
{
	public:
		Hangman();
		~Hangman();
		void displayHangman();
		void readFile(const string filename);
		void userInputs(); 
		void printWords(const int i);
		void outputWords();
		bool checkWinning();
		void playGame();

	private:
	    static const int MAX_CHARACTERS = 15;
	    char wordBank[MAX_CHARACTERS];
	    char userInput[MAX_CHARACTERS];
	    char printArray[MAX_CHARACTERS];
	    int numLives = 6;
	    int n = 0;
	    bool GAMEOVER = false;

};
