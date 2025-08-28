#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid; 
        }
        else if (arr[mid] < key) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter number to search: ";
    cin >> key;

    
    int result1 = linearSearch(arr, n, key);
    if (result1 != -1)
        cout << "Linear Search: Found at index " << result1 << endl;
    else
        cout << "Linear Search: Not found" << endl;

    
    int result2 = binarySearch(arr, n, key);
    if (result2 != -1)
        cout << "Binary Search: Found at index " << result2 << endl;
    else
        cout << "Binary Search: Not found" << endl;

    return 0;
}

