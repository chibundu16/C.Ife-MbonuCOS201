#include <iostream>
using namespace std;
enum week{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
int main(){
    typedef week weekdays;
    weekdays today;
    today = Monday;
    if(today == 1){
    cout << "Today is Monday";
    }else{
        cout << "Today is not Monday";
    }
    return 0;
}