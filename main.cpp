#include <iostream>
#include <ctime>

using namespace std;

int score = 1;

void pickNumber();
void continueGame();

void continueGame() {

    string conGame;

    cout << "Current score: " << score << endl;
    cout << "Want to continue? [y/n]: ";
    cin >> conGame;

    conGame[0] = ::tolower(conGame[0]);
    //First letter in String is only one that really matters

    if (conGame == "y") {
        pickNumber();
    }
    if (conGame == "n") {
        cout << "Your score: " << score << endl;
	_Exit(0);
    }
    else {
        continueGame();
    }

}

void matchNumber(int guessNumber) {

    srand((unsigned) time(0));
    int randomNumber = rand() % 6 + 1;

    if (guessNumber == randomNumber) {
        cout << "You died, game over" << endl;
        _Exit(0);
    }
    else if (guessNumber != randomNumber) {
        score = score * 2;
        continueGame();
    }

}

void pickNumber() {

    int guessNumber;

    cout << "Pick a number between 1 and 6: ";
    cin >> guessNumber;

    if (guessNumber >= 1 & guessNumber <= 6) {
        matchNumber(guessNumber);
    }
    else {
        cout << "You know the rules and so do I" << endl;
        pickNumber();
    }

}

int main() {

    pickNumber();

    return 0;
}
