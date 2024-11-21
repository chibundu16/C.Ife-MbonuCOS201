#include <iostream>
using namespace std;

union mix_t {
    int a;
    struct {
        short hi;
        short lo;
    } s;
    char c[4];
} mix;

int main() {
    cout << "Enter value for int a \n";
    cin >> mix.a;
    cout << "The value for a is " << mix.a << endl;

    cout << "Enter value for short hi\n";
    cin >> mix.s.hi;
    cout << "The value for short hi is " << mix.s.hi << endl;

    cout << "Enter value for short lo\n";
    cin >> mix.s.lo;
    cout << "The value for short lo is " << mix.s.lo << endl;

    cout << "The value for a is " << mix.a << endl;

    return 0;
}