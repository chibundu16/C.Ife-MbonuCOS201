#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Function to scramble a given word
string scramble(const string& text) {
    string chars = text;
    for (int i = 0; i < chars.length(); i++) {
        int j = rand() % chars.length();
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
    return chars;
}

int main() {
    // Array of 10 words for the game
    const int WORD_COUNT = 10;
    string wordList[WORD_COUNT] = {
        "education", "programming", "community", "service", "project",
        "improvement", "language", "application", "student", "guess"
    };

    cout << "Welcome to the Word Scramble Game!\n";
    cout << "Unscramble the letters to guess the word.\n";
    cout << "Type 'exit' to quit the game.\n\n";

    // Loop through each word in the wordList array
    for (int i = 0; i < WORD_COUNT; i++) {
        string scrambledWord = scramble(wordList[i]);
        
        cout << "Scrambled word: " << scrambledWord << "\n";
        cout << "Your guess: ";
        
        string userGuess;
        cin >> userGuess;

        // Check if the user wants to exit
        if (userGuess == "exit") {
            break;
        }

        // Check if the guess is correct
        if (userGuess == wordList[i]) {
            cout << "Correct! Well done.\n\n";
        } else {
            cout << "Incorrect. The correct word was: " << wordList[i] << "\n\n";
        }
    }

    cout << "Thank you for playing!\n";
    return 0;
}