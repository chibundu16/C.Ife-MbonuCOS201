#include <iostream>
#include <new> // For dynamic memory allocation
using namespace std;

int main() {
    int *array;
    int i, j, size;

    cout << "Enter the size of the array: ";
    cin >> size;

    array = new int[size]; // Dynamically allocate array

    // Fill the array with values
    for (i = 0; i < size; i++) {
        array[i] = i;
    }

    // Print the array
    for (j = 0; j < size; j++) {
        cout << "array[" << j << "] = " << array[j] << endl;
    }

    // Free the allocated memory
    delete[] array;

    return 0;
}
