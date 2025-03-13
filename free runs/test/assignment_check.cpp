#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <algorithm>

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
string usernames[8] = {"Bolaji", "Layla", "Danver", "Baxter", "Lava", "Borax", "Tutor", "Oval"};
string passwords[8] = {"look", "man", "noise", "brother", "hot", "movie", "learn", "shape"};
string userAnswers[8];

void viewScript(const string userAnswers[]) {
    for (int i = 0; i < 8; i++) {
        cout << "Question " << i + 1 << ": " << questions[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ". " << options[i][j] << endl;
        }
        cout << "Your choice: " << userAnswers[i] << "\t";
        cout << "Correct choice: " << correct_answers[i] << endl;
    }
}

int main() {
    cout << "WELCOME TO 100 CBT EXAMINATION\n";
    cout << "If you would like to proceed, type 's'. To exit, type 'e'.\n";
    
    char start;
    cin >> start;
    start = tolower(start);
    if (start == 'e') return 0;
    
    // Authentication
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    bool authenticated = false;
    for (int i = 0; i < 8; i++) {
        if (username == usernames[i] && password == passwords[i]) {
            authenticated = true;
            break;
        }
    }
    
    if (!authenticated) {
        cout << "Invalid username or password. Exiting...\n";
        return 0;
    }
    
    cout << "Authentication successful! Press 1 to start or 2 to exit.\n";
    cin >> start;
    if (start != '1') return 0;

    // Question Attempt
    int score = 0;
    for (int i = 0; i < 8; i++) {
        cout << "Question " << i + 1 << ": " << questions[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ". " << options[i][j] << endl;
        }

        string answer;
        while (true) {
            cout << "Enter your answer (A, B, C, D): ";
            cin >> answer;
             transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
            if (answer == "A" || answer == "B" || answer == "C" || answer == "D") {
                break;
            } else {
                cout << "Invalid input. Please try again.\n";
            }
        }
        
        userAnswers[i] = answer;
        if (answer == correct_answers[i]) score++;
    }
    
    // Results
    cout << "You scored " << score << " out of 8.\n";
    string response;
    cout << "Would you like to view your script? [y/n]: ";
    cin >> response;
    if (response == "y" || response == "Y") {
        viewScript(userAnswers);
    }

    return 0;
}
// I made use of the AI when it came to being able to convert my user answers in lower case to upper case, learning the use of algorithm library to do so.