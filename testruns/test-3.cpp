#include <iostream>
#include <vector>
#include <ctime> // For time management

using namespace std;

#define TOTAL_QUESTIONS 5
#define TIME_LIMIT 60 // Time limit in seconds

// Mock Data
char userAnswers[TOTAL_QUESTIONS] = {'-', '-', 'B', '-', 'C'}; // '-' means unanswered
string questions[TOTAL_QUESTIONS] = {
    "What is 2 + 2?",
    "What is the capital of France?",
    "What is 5 x 6?",
    "What is the square root of 16?",
    "Who wrote '1984'?"
};

void displayQuestion(int index) {
    cout << questions[index] << endl;
    cout << "Options: A, B, C, D" << endl;
}

void getUserAnswer(int index) {
    char answer;
    cout << "Your answer: ";
    cin >> answer;
    userAnswers[index] = answer; // Store the answer
}

void attemptUnansweredQuestions() {
    vector<int> unansweredIndices; // Record of unanswered question indices

    // Populate unansweredIndices
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (userAnswers[i] == '-') {
            unansweredIndices.push_back(i);
        }
    }

    // Start the timer
    time_t startTime = time(0);
    
    for (int i = 0; i < unansweredIndices.size(); i++) {
        int questionIndex = unansweredIndices[i];
        
        // Check time limit
        if (difftime(time(0), startTime) >= TIME_LIMIT) {
            cout << "\nTime is up! No more questions can be attempted.\n";
            break;
        }

        // Attempt the unanswered question
        cout << "\nAttempting question Q" << questionIndex + 1 << ": ";
        displayQuestion(questionIndex);
        getUserAnswer(questionIndex);
    }
}

int main() {
    cout << "Unanswered Questions Session Begins:\n";
    attemptUnansweredQuestions();

    // Display final answers
    cout << "\nFinal Answers:\n";
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        cout << "Q" << i + 1 << ": " << userAnswers[i] << endl;
    }
    
    return 0;
}
