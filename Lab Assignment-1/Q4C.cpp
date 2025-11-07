#include <iostream>
using namespace std;

int main() {
    int a[10][10], transpose[10][10];
    int rows, cols;

    cout << "Enter rows and columns of the matrix: ";
    cin >> rows >> cols;


    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];


    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transpose[j][i] = a[i][j];


    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << transpose[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
