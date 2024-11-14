#include <iostream>
using namespace std;
int main(){
    int x = 27;
    int *ip;
    ip = &x;
    cout << "value of x is : ";
    cout << x << endl;
    cout << "value of ip is : ";
    cout << ip << endl;
    cout << "value of *ip is : ";
    cout << *ip << endl;
    return 0;
}