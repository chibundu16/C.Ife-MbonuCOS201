#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int playerGuess = 0;
    int numberOfTries = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have selected a number between 1 and 100.\n";
    cout << "Can you guess what it is?\n";

    // Main game loop
    while (true) {
        cout << "Enter your guess: ";
        cin >> playerGuess;
        numberOfTries++;

        if (playerGuess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else if (playerGuess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number in " << numberOfTries << " tries.\n";
            break;
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}
