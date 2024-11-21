#include <iostream>
using namespace std;
void passpointer(int *p){
    cout <<"In the function" << endl;
    cout << "*p = " << *p << endl;
    cout << "p = " << p << endl;
}

int main (){
    int num = 9;
    passpointer(&num);
    return 0;
}