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


string submit;
int score;
int main(){
    cout << "WELCOME TO 100 LEVEL CBT EXAMINATION" << endl;
    cout << "If you would like to proceed type in s ! \n If not type in e to exit" << endl;
    go:
    char start;
    cin >> start;
    start = tolower(start);
    if (start == 'e') return 0;
   
    string name;
    string password;
    cout << "Enter your username :";
    cin >> name ;
    cout << "Enter your password :";
    cin >> password ;

    bool authenticated = false;
    for (int i = 0; i < 8; i++) {
        if (name == usernames[i] && password == passwords[i]) {
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
    if (start == 'e') return 0;

    while(1){
     cout << "Welcome!! \nTo proceed press s \nTo exit press e \n---------------------" << endl;
    cin >> start ;

    if (start == 's'){
        cout << "Loading ..." << endl;
        break;
    }
    else if (start == 'e'){
        cout << "You have exited !!" << endl;
        return 0;
    }
    else {
        cout << "Enter A valid number to continue" << endl;
    }
    }

    cout << "To go to next question press 'N' \n"
            "To go back press 'P' \n"
            "To submit press 'V' \n"
            "----------------------------------\n";

    int i=0;
    while(i < 8) {
        cout << "Question " << i + 1 << ": " << questions[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << char('A' + j) << ". " << options[i][j] << endl;
        }

        string answer;
        string submit;
         

        while (true) {
            cout << "Enter your answer (A, B, C, D): ";
            cin >> answer;
             transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
            if (answer == "A" || answer == "B" || answer == "C" || answer == "D") {
                break;
            }else if (answer == "N" || answer == "n") {
                if (i == 7){
                    cout << "This is the last question. You can't go forward.\n"
                        << "Press 'V' to submit or 'P' to go back.\n";
                }else{
                    break;
                }
            }else if (answer == "P" || answer == "p") {
                if (i > 0) {
                    i-=2;
                   break;
                }else {
                    cout << "This is the first question. You can't go back.\n";
                }
            }else if (answer == "V" || answer == "v") {
                cout << "Are you sure you want to submit? \nEnter 'Y' to submit or 'N' to cancel: ";
                cin >> submit;
                if (submit == "Y" || submit == "y") {
                    i=8;
                    break; 
                } else if (submit == "N" || submit == "n") {
                    continue;
                }
            }else{
                cout << "Invalid option... try again.\n";
            }

        }
    userAnswers[i] = answer;
    i++;
    


}
for (int i = 0; i < 8; i++) {
    if (correct_answers[i] == userAnswers[i]) {
            score++;
        }
}

cout << "You got " << score << " out of 8.\n";
string answer;
while (true) {
    cout << "Would you like to view your script? [y/n]: ";
    cin >> answer;

    if (answer == "y" || answer == "Y") {
        viewScript(userAnswers);
        break;
    } else if (answer == "n" || answer == "N") {
        break;
    } else {
        cout << "Invalid input. Try again.\n";
    }
}
}