#include <iostream>
using namespace std;

const int TOTAL_QUESTIONS = 10;

const char questions[TOTAL_QUESTIONS][100] = {
    "What is the capital of Nigeria?",
    "When did Nigeria gain independence?",
    "What is the best university in Nigeria?",
    "What year did Nigeria become a republic?",
    "What is 2 + 2?",
    "What is the capital of France?",
    "What is the largest planet in our solar system?",
    "Who owns Tesla ?",
    "who wrote the book 'THINGS FALL APART' ?", 
    "Is Programming scary?"
};

const char options[TOTAL_QUESTIONS][9][50] = {
    {"Abuja", "Lagos", "Niger", "Benue"},
    {"1960", "1984", "1932", "1944"},
    {"ABUAD", "PAU", "NILE", "BABCOCK"},
    {"1845", "1963", "1764", "1945"},
    {"10", "6", "8", "4"},
    {"Paris", "London", "Berlin", "Madrid"},
    {"Earth", "Jupiter", "Saturn", "Mars"},
    {"Elon Musk", "Joe Biden ", "Trigga Nucci", "Alonso"},
    {"Chinua Achebe", "Joe Biden ", "Marcus Rashford", "Thomas Edison"},
    {"YES", "NO", "MAYBE", "DEFINITELY"}

};

const char correctAnswers[TOTAL_QUESTIONS] = {'A', 'A', 'A', 'B', 'D', 'A', 'B', 'A', 'A', 'D'};
char userAnswers[TOTAL_QUESTIONS] = {'-', '-', '-', '-', '-'};

int displayQuestion(int index) {
    if (index < 0 || index >= TOTAL_QUESTIONS) {
        cout << "Invalid question index.\n";
        return -1; 
    }

    // Display the question
    cout << "\nQ" << index + 1 << ": " << questions[index] << endl;

    // Display the options
    for (int i = 0; i < 4; i++) {
        cout << (char)('A' + i) << ". " << options[index][i] << endl;
    }

    return 0; 
}

void getUserAnswer(int index) {
    char answer;
    while (true) 
    { cout << "Enter your choice (A/B/C/D) or 'S' to skip: ";
    cin >> answer;
    answer = toupper(answer);

    if (answer == 'S') {
        cout << "Question skipped.\n";
        break;
    } else if (answer >= 'A' && answer <= 'D') {
        userAnswers[index] = answer;
        break;
    } else {
        cout << "Invalid input. Please try again.\n";
        getUserAnswer(index); 
    }
    }
   
}
void SkippedQuestions() {
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (userAnswers[i] == '-') {  
            cout << "\nYou skipped Q" << i + 1 << ": " << questions[i] << endl;
            cout << "Options:\n";
            for (int j = 0; j < 4; j++) {
                cout << (char)('A' + j) << ". " << options[i][j] << endl;
            }
        }
    }
}

void attemptUnansweredQuestions() {
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        if (userAnswers[i] == '-') { // Unanswered questions
            cout << "\nAttempt unanswered question Q" << i + 1 << ": " << questions[i] << endl;
            displayQuestion(i);
            getUserAnswer(i); // Let user attempt the question
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

void displayResponses() {
    cout << "\nYour responses:\n";
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        cout << "Q" << i + 1 << ": ";
        
        
        if (userAnswers[i] == '-') {
            cout << "Not answered" << endl;
        } else {
            
            cout << string(1, userAnswers[i]) << endl;
        }
    }
}

int main() {
    cout << "\n WELCOME TO THE CBT TEST \n";

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        displayQuestion(i);
        getUserAnswer(i);
    }

     attemptUnansweredQuestions();

    cout << "\nYour skipped questions...\n";
    SkippedQuestions();

     int grade = calculateScore();
    displayScore(grade);

     char readyToSubmit;
    cout << "\nAre you ready to submit your answers? (Y/N): ";
    cin >> readyToSubmit;

    if (toupper(readyToSubmit) == 'Y') {
        // Calculate and display score
        int grade = calculateScore();
        displayScore(grade);
        cout << "\nThank you for completing the test!\n";
    } else {
        displayScore(grade);
        cout << "\nYou can review or retake the test.\n";
    }

    cout<<"\nWould you like to view your responses? (Y/N): ";


   
        displayResponses();
    
    cout << "\nThank you for playing!\n";
    return 0;
}



