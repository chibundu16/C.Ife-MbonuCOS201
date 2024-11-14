#include <iostream>
using namespace std;

int main(){
    const int size = 1;
    char arr[size];
    cout <<"Enter any letter of your choice"<< endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter a valid letter for checking : ";
        cin >> arr[i];
}
    char letter = arr[0];
    
    // Check if the character is a vowel
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
        letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
        cout << letter << " is a vowel." << endl;
    }
    else if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
        // If it's a letter but not a vowel, it must be a consonant
        cout << letter << " is a consonant." << endl;
    }
    else {
        cout << "Please enter a valid letter." << endl;
    }

    return 0;
}