#include <iostream>
using namespace std;

int main() {
    const int SIZE = 3;
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], output[SIZE][SIZE];

    // Input elements of the first matrix
    cout << "Enter elements of the first 3x3 matrix:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "Enter element at position [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix1[i][j];
        }
    }

    // Input elements of the second matrix
    cout << "Enter elements of the second 3x3 matrix:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "Enter element at position [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix2[i][j];
        }
    }

    // Adding both matrices and storing the result in the output matrix
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            output[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Displaying the sum of the two matrices
    cout << "Sum of the two matrices:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
