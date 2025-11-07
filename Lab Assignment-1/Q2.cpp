#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    sort(arr, arr + n);

    
    int i = 0; 
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    int newSize = i + 1;

    cout << "Array after removing duplicates: ";
    for (int k = 0; k < newSize; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}
