#include <iostream>
using namespace std;

void create(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for index " << i << ": ";
        cin >> A[i];
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void insert(int A[], int &n)
{
    int pos, val;
    cout << "Enter position: ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    for (int i = n; i > pos; i--)
    {
        A[i] = A[i - 1];
    }
    A[pos] = val;
    n++;
}

void del(int A[], int &n)
{
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    for (int i = pos; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }
    n--;
}

void linearSearch(int A[], int n)
{
    int val;
    cout << "Enter value to search: ";
    cin >> val;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == val)
        {
            cout << "Found at index " << i << endl;
            return;
        }
    }
    cout << " Number not found" << endl;
}

int main()
{
    int A[100];
    int n = 0;

    while (true)
    {
        int user;
        cout << "\nMENU\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Linear Search\n6. Exit\n";
        cin >> user;

        switch (user)
        {
        case 1:
            cout << "Enter size: ";
            cin >> n;
            create(A, n);
            break;
        case 2:
            display(A, n);
            break;
        case 3:
            insert(A, n);
            break;
        case 4:
            del(A, n);
            break;
        case 5:
            linearSearch(A, n);
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
}
