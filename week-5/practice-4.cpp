//array example to find the largest number of three numbers
#include <iostream>
using namespace std;
int main() {
    const int size = 3;
    int arr[size];
    cout << "Enter "<< size <<" different numbers:"<<endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter a valid number for checking : ";
        cin >> arr[i];
}
int largest_number = arr[0];
for(int i =0;i<4;i++){
    if (arr[i]>largest_number){
        largest_number = arr[i];
}
}
cout<<"The largest number is "<< largest_number<<endl;
}