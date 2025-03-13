#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string scramble(string word){
    string scrambled;
    int word_length = word.length();
   
    while (word_length> 0){
        int remove_index = rand() % word_length;
        scrambled += word[remove_index];
        word.erase(remove_index,1);
        word_length-=1;
    }

    return scrambled;
}

class Question{
    public:
    string q_word;
    string output;
    string scrambled;

    Question(string word){
        q_word = word;
        scrambled = scramble(word);
        while (output.length() < word.length()){
            output += '-';
        }

    };
    
    void display_hint(){
    	int random_index = rand() % q_word.length();
    	do{
    		random_index = rand() % q_word.length();
		}while (output[random_index] != '-');
		
        output[random_index] = q_word[random_index];
        cout<<output<<endl;

    }

};

string lowercase(string word){
    for (int i=0; i<word.length(); i++){
        word[i]= tolower(word[i]);
    }
    return word;
}

int main(){
    int attempts = 5;
    int score = 0;
    srand(time(0));
    char response;
    const string words[] = {"nigger","jigger","balls","niggerjiggerballs"};
    
    
    do{
        cout<<"Enter s to start and e to exit"<<endl;
        cin>>response;
        response = tolower(response);

        if (!(response == 's'||response == 'e'))
        cout<<"Invalid Character Entered"<<endl;
        
    }while (!(response == 's'||response == 'e'));
    
    if (response == 'e'){return 0;};
	
    cin.ignore();
	cout<<"Welcome to the Spelling thingy"<<endl;
	cout<<"Instructions:\nUnscramble the hidden word. If you're stuck, you can press '#hint' for a hint.Type '#next' to see the answer and move to the next question if you're stuck. You have 5 hints. A correct question gives you more hints. Goodluck"<<endl;
	
	int active_question =0;
    int length = sizeof(words) /sizeof(words[0]);
    while(1==1){
        Question q(words[active_question]);

        run:
        cout<<q.scrambled<<": "<<endl;
        string response;
        getline(cin, response);
        response = lowercase(response);

        if (active_question == length -1){
            cout<<"This is the last question!"<<endl;
        }

        if (response == q.q_word){
            cout<<"Correct! You spelled the word correctly."<<endl;
            score++;

            cout<<"You've gotten "<<score<<"out of "<<active_question<<endl;

        }else if(response == "#hint"){
            if (attempts >0){
                attempts--;
                cout<<"Here's a hint! You have "<<attempts<<" remaining."<<endl;
                q.display_hint();
                continue;
            }else{
                cout<<"You have no more hints remaining! Try harder"<<endl;
                goto run;
            }
            

        }else if (response == "#next"){
            if (active_question + 1 == length){
                break;
            };
            cout<<"Question Skipped!"<<endl;
            continue;

        }else{
            cout<<"Incorrect Spelling!"<<endl;
            goto run;
        }
        active_question++;

        if (active_question + 1 == length){
                break;
            };


    }


}