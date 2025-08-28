#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int size = n * (n+1) / 2;
    int lower[size];

    cout << "Enter lower triangular elements: ";
    for (int i = 0; i < size; i++) {
        cin >> lower[i];
    }

    cout << "\nLower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << lower[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
