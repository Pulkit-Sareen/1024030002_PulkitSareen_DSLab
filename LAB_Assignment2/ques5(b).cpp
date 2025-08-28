#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int tri[3*n - 2]; 

    cout << "Enter tri-diagonal elements: ";
    for (int i = 0; i < 3*n - 2; i++) {
        cin >> tri[i];
    }

    cout << "\nTri-Diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j+1 || i+1 == j) cout << tri[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
