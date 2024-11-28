#include <iostream>
#include <cstring> // For string operations
#include <cctype>  // For character manipulation (tolower/toupper)

using namespace std;

const int TOTAL_QUESTIONS = 5;
const int MAX_OPTION_LENGTH = 30;

// Questions, options, and correct answers
const char questions[TOTAL_QUESTIONS][100] = {
    "What is the capital of France?",
    "What is 2 + 2?",
    "Who wrote 'Hamlet'?",
    "What is the chemical symbol for water?",
    "What is the largest planet in our solar system?"
};

const char options[TOTAL_QUESTIONS][4][MAX_OPTION_LENGTH] = {
    {"A. Paris", "B. London", "C. Berlin", "D. Madrid"},
    {"A. 3", "B. 4", "C. 5", "D. 6"},
    {"A. Charles Dickens", "B. William Shakespeare", "C. Mark Twain", "D. J.K. Rowling"},
    {"A. H2", "B. O2", "C. H2O", "D. CO2"},
    {"A. Earth", "B. Jupiter", "C. Saturn", "D. Mars"}
};

const char correctAnswers[TOTAL_QUESTIONS] = {'A', 'B', 'B', 'C', 'B'};
char userAnswers[TOTAL_QUESTIONS] = {'-', '-', '-', '-', '-'}; // Initialize as unanswered

void displayQuestion(int index) {
    cout << "\nQ" << index + 1 << ": " << questions[index] << endl;
    for (int i = 0; i < 4; i++) {
        cout << options[index][i] << endl;
    }
}

void getUserAnswer(int index) {
    char answer;
    cout << "Enter your answer (A/B/C/D) or 'S' to skip: ";
    cin >> answer;
    answer = toupper(answer); // Convert to uppercase for consistency

    if (answer == 'S') {
        cout << "Question skipped.\n";
    } else if (answer >= 'A' && answer <= 'D') {
        userAnswers[index] = answer;
    } else {
        cout << "Invalid input. Please try again.\n";
        getUserAnswer(index); // Retry
    }
}

void reviewSkippedQuestions() {
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (userAnswers[i] == '-') {
            cout << "\nYou skipped Q" << i + 1 << ".\n";
            displayQuestion(i);
            getUserAnswer(i);
        }
    }
}

int calculateScore() {
    int score = 0;
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (userAnswers[i] == correctAnswers[i]) {
            score++;
        }
    }
    return score;
}

void displayScore(int score) {
    cout << "\nYour score: " << score << " / " << TOTAL_QUESTIONS << endl;
}

void displayUserResponses() {
    cout << "\nYour responses:\n";
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        cout << "Q" << i + 1 << ": " << (userAnswers[i] == '-' ? "Not answered" : string(1, userAnswers[i])) << endl;
    }
}

int main() {
    cout << "Welcome to the Quiz Game!\n";

    // Loop through all questions
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        displayQuestion(i);
        getUserAnswer(i);
    }

    // Review skipped questions
    cout << "\nReviewing skipped questions...\n";
    reviewSkippedQuestions();

    // Calculate and display the score
    int score = calculateScore();
    displayScore(score);

    // Optionally display responses
    char viewScript;
    cout << "\nWould you like to view your responses? (Y/N): ";
    cin >> viewScript;
    if (toupper(viewScript) == 'Y') {
        displayUserResponses();
    }

    cout << "\nThank you for playing!\n";
    return 0;
}
