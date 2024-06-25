#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

int main() {
    srand(time(0));

    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;

    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    while (userGuess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess > randomNumber) {
            cout << "Your guess is too high." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Your guess is too low." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number." << endl;
        }
    }

    return 0;
}
