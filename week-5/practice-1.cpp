//arrays example summing up value in the array
#include <iostream>
using namespace std;
short score [] = {6,3,4,2,4};
int n;
double result=0;
int main (){
    for (n=0 ; n<5 ; n++ ){
        result += score[n];
    }
    cout << result;
    
}