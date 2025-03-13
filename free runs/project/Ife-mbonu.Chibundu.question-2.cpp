#include <iostream>
#include <string>
using namespace std;

string scramble(string input){
    srand(time(0));
    string scrambledword;
    int scrambs = input.length();

    while(scrambs > 0){
        int random_index = rand() % scrambs;
        scrambledword += input[random_index];
        input.erase(random_index,1);
        scrambs--;
    }
    return scrambledword;
}

string lowercase(string input){
    for(int i = 0; i < input.length();i++){
        char c;
        c = tolower(input[i]);
        input[i] = c;
    }
    return input;
}

int main(){
    cout << "WELCOME TO SPELLING ENHANCEMENT CLINIC" << endl;
    cout << "If you would like to proceed type in s ! \n If not type in e to exit" << endl;
    char start;
    cin >> start;
    tolower(start);
    if (start == 'e'){
        return 0;
    }
    cout << "Attempt to unscramble the words. For word assistance input G. For hint input h" << endl;
    string listofwords[] = {"broken", "laptop", "girlfriend", "dolls", "dollars"};
    string hints[] = {"shatter","coding","companion","play","cash"};
    int length = sizeof(listofwords) / sizeof(listofwords[0]);

    cin.ignore();
    int score = 0;

    int get_correct_letter_five = 5;
    

    for (int i = 0; i < length; i++) {
        int get_correct_position = 1;
        string scrambledword = scramble(listofwords[i]);
        if (i == length-1){
            cout<<"Hello , this is the LAST question"<<endl;
        }

        while(1==1){
        cout << scrambledword << endl;
        string user_answer;
        cin>>user_answer;
        user_answer = lowercase(user_answer);


        if (user_answer == listofwords[i]){
            score++;
            cout << "You spelt the word correctly!" << endl;
            cout << "Your score is " << score << "/5" << endl;
            get_correct_letter_five++;
            break;
        } else if (user_answer == "g") {

            if (get_correct_letter_five > 0) {
                cout << "Correct Position: ";
                for (int j = 0; j < get_correct_position; j++) {
                    cout << listofwords[i][j];
                }
                cout << endl;

                get_correct_letter_five--;
                get_correct_position++; 
                continue;

            } else {
                cout << "You have exhausted your hints!" << endl;  
            }

        } else if (user_answer == "n") {
            cout << "Question Skipped!" << endl;
            cout<<"The correct word was: "<<listofwords[i]<<endl;
            break;
        } else if (user_answer == "h") {
            cout << "Hint: " << hints[i] << endl;
        } else {
            cout << "Incorrect Spelling!" << endl;
        }
        }
    } 

    cout<<"Your Score is "<<score<<" out of "<<length<<endl;
    return 0; 
}