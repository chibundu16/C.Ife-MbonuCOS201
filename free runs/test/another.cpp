#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const string questions[8] = {
    "What school is this?",
    "How many buildings are there in this school?",
    "Who are you?",
    "What is the capital of Nigeria?",
    "When did Nigeria gain independence?",
    "What is the best university in Nigeria?",
    "What year did Nigeria become a republic?",
    "What is 2 + 2?"
};

const string options[8][4] = {
    {"Babcock University", "Pan-Atlantic University", "Covenant University", "None of the above"},
    {"2", "50", "10", "6"},
    {"A Doctor", "A Monkey", "A Student", "A Surgeon"},
    {"Abuja", "Lagos", "Niger", "Benue"},
    {"1960", "1984", "1932", "1944"},
    {"ABUAD", "PAU", "NILE", "BABCOCK"},
    {"1845", "1963", "1764", "1945"},
    {"10", "6", "8", "4"}
};

const string correct_answers[8] = {"B", "A", "C", "A", "A", "B", "B", "D"};

void viewScript(const vector<string>& userAnswers) {
    for (int i = 0; i < 8; i++) {
        cout << "Question " << i + 1 << ": " << questions[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ". " << options[i][j] << endl;
        }
        cout << "Your choice: " << (userAnswers[i] == "" ? "Skipped" : userAnswers[i]) << "\t";
        cout << "Correct choice: " << correct_answers[i] << endl;
    }
}

int main() {
    vector<string> userAnswers(8, ""); // To store user's answers
    int currentQuestion = 0;
    int score = 0;
    string userInput;

    while (true) {
        // Display current question
        cout << "Question " << currentQuestion + 1 << ": " << questions[currentQuestion] << endl;
        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ". " << options[currentQuestion][j] << endl;
        }
        cout << "Enter your answer (A, B, C, D), 'N' for next, 'P' for previous, 'S' to submit: ";
        cin >> userInput;
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper); // Convert input to uppercase

        if (userInput == "A" || userInput == "B" || userInput == "C" || userInput == "D") {
            userAnswers[currentQuestion] = userInput; // Store the answer
            cout << "Answer saved.\n";
        } else if (userInput == "N") {
            if (currentQuestion < 7) {
                currentQuestion++;
            } else {
                cout << "You are already on the last question.\n";
            }
        } else if (userInput == "P") {
            if (currentQuestion > 0) {
                currentQuestion--;
            } else {
                cout << "You are already on the first question.\n";
            }
        } else if (userInput == "S") {
            cout << "Are you sure you want to submit? (Y/N): ";
            cin >> userInput;
            transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
            if (userInput == "Y") {
                break; // Exit the loop to submit
            }
        } else {
            cout << "Invalid input. Please try again.\n";
        }
    }

    // Calculate score
    for (int i = 0; i < 8; i++) {
        if (userAnswers[i] == correct_answers[i]) {
            score++;
        }
    }

    // Display results
    cout << "You scored " << score << " out of 8.\n";

    // View script
    cout << "Would you like to view your script? (Y/N): ";
    cin >> userInput;
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
    if (userInput == "Y") {
        viewScript(userAnswers);
    }

    return 0;
}
