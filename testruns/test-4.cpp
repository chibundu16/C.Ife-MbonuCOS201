#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to scramble the letters of a word
string scrambleWord(string word) {
    string scrambled = word;
    random_shuffle(scrambled.begin(), scrambled.end());
    return scrambled;
}

// Function to display the word with unrevealed letters as underscores
string displayWord(const string& word, const char revealedLetters[], int revealedCount) {
    string displayed;
    for (char c : word) {
        bool revealed = false;
        for (int i = 0; i < revealedCount; i++) {
            if (revealedLetters[i] == c) {
                revealed = true;
                break;
            }
        }
        displayed += revealed ? c : '_';
    }
    return displayed;
}

int main() {
    // Word bank as a simple array of strings
    const int WORD_COUNT = 7;
    string wordBank[WORD_COUNT] = {
        "education", "community", "service", "secondary", "students", "correct", "application"
    };

    int score = 0;
    int totalWords = WORD_COUNT;
    int correctLetterAttempts = 5;
    char revealedLetters[50]; // Array to store revealed letters
    int revealedCount = 0;

    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    // Shuffle the word bank
    for (int i = 0; i < WORD_COUNT; i++) {
        int randIndex = rand() % WORD_COUNT;
        swap(wordBank[i], wordBank[randIndex]);
    }

    cout << "Welcome to the Spelling Improvement Application!" << endl;
    cout << "Press 'S' to start or 'E' to exit." << endl;

    char choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'e') {
            cout << "Thank you for using the application. Goodbye!" << endl;
            return 0;
        } else if (choice == 's') {
            break;
        } else {
            cout << "Wrong character entered. Please enter 'S' to start or 'E' to exit." << endl;
        }
    }

    // Game loop
    for (int idx = 0; idx < WORD_COUNT; ++idx) {
        string word = wordBank[idx];
        string scrambled = scrambleWord(word);
        revealedCount = 0; // Reset revealed letters for each word

        cout << "\nWord " << (idx + 1) << "/" << totalWords << ": " << scrambled << endl;

        while (true) {
            cout << "Revealed word so far: " << displayWord(word, revealedLetters, revealedCount) << endl;
            cout << "Score: " << score << "/" << totalWords
                 << " | Correct Letter Attempts: " << correctLetterAttempts << endl;
            cout << "Options: [G]uess, [H]int, [N]ext, [C]orrect Letter" << endl;

            char action;
            cout << "Choose an option: ";
            cin >> action;
            action = tolower(action);

            if (action == 'g') {
                string guess;
                cout << "Enter your guess: ";
                cin >> guess;

                // Convert guess to lowercase for case-insensitivity
                transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

                if (guess == word) {
                    score++;
                    correctLetterAttempts++;
                    cout << "Correct! You spelt the word correctly." << endl;
                    cout << "Updated Score: " << score << "/" << totalWords << endl;
                    break;
                } else {
                    cout << "Incorrect spelling." << endl;
                }

            } else if (action == 'h') {
                cout << "Hint: The word relates to a topic in the word bank!" << endl;

            } else if (action == 'n') {
                cout << "Skipping! The correct word was: " << word << endl;
                break;

            } else if (action == 'c') {
                if (correctLetterAttempts > 0) {
                    correctLetterAttempts--;
                    // Reveal one unrevealed letter
                    for (char c : word) {
                        bool alreadyRevealed = false;
                        for (int i = 0; i < revealedCount; i++) {
                            if (revealedLetters[i] == c) {
                                alreadyRevealed = true;
                                break;
                            }
                        }
                        if (!alreadyRevealed) {
                            revealedLetters[revealedCount++] = c;
                            break;
                        }
                    }
                    cout << "Revealed one correct letter." << endl;
                } else {
                    cout << "No more 'GET CORRECT LETTER' attempts left." << endl;
                }

            } else {
                cout << "Invalid option. Please try again." << endl;
            }
        }

        if (idx == WORD_COUNT - 1) {
            cout << "This is the last word." << endl;
        }
    }

    cout << "\nGame Over! Your final score is " << score << "/" << totalWords << "." << endl;
    cout << "Thank you for playing!" << endl;

    return 0;
}
