#include <iostream>
#include <string>
#include <random>
# include <cstdlib>
using namespace std;
string scrambled (const string& text) {
    string chars = text;
    for (int i = 0; i < chars.length(); i++) {
        int j = rand() % chars.length();
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
    return chars;
}

int main(){
    const int words = 10; 
    string list_of_words[words] = { "love", "kindness", "relationship", "education", "mindset", 
    "lipgloss", "magician", "malnutrition", "muscular", "abstractions"};

    for (int i = 0; i < words; i++) {
        string scrambled_word = scrambled(list_of_words[i]);
        
        cout << "Scrambled word: " << scrambled_word << "\n";
        cout << "Your guess: ";
        
         string guess;
         cin >> guess;
        
        if (guess == list_of_words[i]) {
            cout << "Correct! Well done.\n\n";
        } else {
            cout << "Incorrect. The correct word was: " << list_of_words[i] << "\n\n";
        }
        }
}