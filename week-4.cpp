#include <iostream>
using namespace std;

int main(){
    /**{
        int i;
    int j;
    int n;
    cout << "Enter value for n :" << endl;
    cin >> n;
    for(i = 1; i < n + 1; i++){
        for(j = 1; j < 13; j++){
            cout << i << "*" << j << "=" << i*j << "\t";
        }
    cout << endl ;
    }
    return 0;
}**/{
    int i;
    int x;
    int y;
    int sum;
    cout << "Enter upper limit:" << endl;
    cin >> x;
    cout << "Enter lower limit:" << endl;
    cin >> y;
    if(x > y){
        for(i = x; i < y+1; i++){
            if (i % 2 != 0){
                cout << i << "\t";
                sum += i;
            }
    }
    }
    else if(x < y){
        for(i = x; i < y+1; i++){
            if (i % 2 != 0){
                cout << i << "\t";
                sum += i;
            }
    }
    
}
else if (x == y and x % 2 != 0){
    cout << x <<"\t";
    sum = x;
}
else{
    cout <<"Invalid Input";
    sum = 0;  
}
cout << endl << "The sum of all the numbers between "<< x << " and " << y << " is " << sum << endl;
}{
    
}
{
    string str = "Pan Atlantic University";
    string str2 = "Pan-Atlantic University";
    cout << "str.compare(str2):" << str.compare(str2) << endl;
    cout << "str.length() : " << str.length() << endl;
    cout << "str.size() : " << str.size() << endl;
    // swap strings
    str.swap(str);
    cout << "str.swap(str2):" << str << endl;
    // create a substring
    int position = 0;
    int number = 5;
    cout << "str.substr(position,number) :" << str.substr(position, number); cout << endl;
}
}
