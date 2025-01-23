#include <iostream>
using namespace std;
float num, ans, denom;

int main(){
    cout << "Handling Exceptions" << endl;
    cout << "Enter numerator" << endl;
    cin >> num;
    cout << "Enter denominator" << endl;
    cin >> denom;
    try {
        if (denom == 0)
        throw denom;
        ans = num/denom;
        cout<<"output :"<<ans;
    }catch(float e){
        cout <<"The denominator is Zero";
    }
    return 0;
}