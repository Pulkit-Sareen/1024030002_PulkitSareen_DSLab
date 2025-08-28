#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string arr[] = {"banana", "apple", "cherry", "date"};
    int n = 4;

    sort(arr, arr+n); 

    cout << "Strings in alphabetical order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
