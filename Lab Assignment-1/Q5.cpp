#include <iostream>
using namespace std;

int main() {
    int a[10][10], rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];


    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++)
            rowSum += a[i][j];
        cout << "Sum of row " << i + 1 << " = " << rowSum << "\n";
    }


    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++)
            colSum += a[i][j];
        cout << "Sum of column " << j + 1 << " = " << colSum << "\n";
    }

    return 0;
}
