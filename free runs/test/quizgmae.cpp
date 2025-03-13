
#include <iostream>
using namespace std;


const string questions[3] = {" What school is this? :",
                    "how many building are there in this school? :",
                    "who are you? :"
};

const string options [3][4] = {
{"Babcock university" ,"pan-atlantic univeristy", "covenant univeristy","None of the above"},
{"2","50","10","6"},
{"A Doctor","A Monkey","A Student","A Surgeon"}
};

string correct_answers[3][2]={
{"b","B"},
{"a","A"},
{"c","C"}
};

string userInput ;
char start;
string submit;
string userInputArray[3]; 
int score;

void viewScript(){
        for (int i=0; i<3; i++){
            cout << "Question " << i+1 << ". :" << endl;
            cout << questions[i] << endl;
            
            for (int j=0; j<4; j++ ){
                cout << char('A' + j) <<"." << options[i][j]<<endl;
            }
            cout << "Your choice: " << userInputArray[i] <<"\t" ;
            cout << "correct choice " << correct_answers[i][0] << endl;
           
        } 
    
    }


int main(){
    cout << "Welcome!! \nTo start press 1 \nTo exit press 2 \n---------------------" << endl;
    cin >> start ;

    if (start == '1'){
        cout << "Loading ..." << endl;
    }
    else if (start == '2'){
        cout << "You have exited !!" << endl;
        return 0;
    }
    else {
        cout << "Enter A valid number to continue" << endl;
        cin >> start;
    }

    cout << "To go to next question press 'N' \n"
            "To go back press 'P' \n"
            "To submit press 'V' \n"
            "----------------------------------\n";

    for (int i=0; i<3; i++){
        cout << "Question " << i+1 << ". :" << endl;
        cout << questions[i] << endl;

            for (int j=0; j<4; j++ ){
                cout << char('A' + j) <<"." << options[i][j]<<endl;}

    bool validInput = true;
    while(!validInput){
        
        cout << "Enter your answer :";
        cin >> userInput; 

        if (userInput == "a" || userInput == "b"|| userInput == "c" || userInput == "d" || userInput == "A" || userInput == "B" || userInput == "C" || userInput == "D"){
            cout << "you selected : " << userInput << endl;
            validInput = true;
            userInputArray[i] = userInput;

        }
        else if (userInput =="N" || userInput == "n"){
            if (i<2){
                validInput =true;
            }
            else{
                cout << "This is the last question. You can't go back \n press 'V' to submit or 'P' to go back"  <<endl;
            }
        }
        else if (userInput == "P" || userInput == "p") {
                if(i>0){
                    i-=2;
                    validInput =true;
                }
                else{
                    cout << "This is the first question. You can't go back \n";
                }  
        }
        else if (userInput == "V" || userInput =="v"){
            cout << "Are you sure you want to submit? \nEnter 'Y' to submit \n Enter 'N' to cancel :" <<endl;
            cin>>submit;
                if (submit == "Y" || submit == "y" ){
                    i=3;
                    validInput = true;
                }
                else if (submit == "N" || submit == "n"){
                   continue;
                }
                
        }
        else{
            cout << "invalid option... try again" <<endl;
        }
        cout << "----------------------------------\n";
    }
    }
    // to get scores
    for(int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            if (correct_answers[i][j] == userInputArray[i]){
                score++;
            }
        }
    }
    string response;
    cout << "You got  " << score << " out of 3 \n" << endl;

    while(true){
        cout << "Would you like to view your script? [y/n]" <<endl;
        cin >> response;
        if (response == "y" || response == "Y"){
            viewScript();
            break;
        }
        else if(response == "n" || response == "N"){
            break;
        }
        else{
            cout << "Invalid input " << endl; 
        }
    }

    return 0;
}
    
