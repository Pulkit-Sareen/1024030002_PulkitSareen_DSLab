#include <iostream>
using namespace std;
int main()
{
    int arr[100], n;
    cout<<"Enter the size of the array=";
    cin>>n;
    cout << "Enter the elements inside the array=";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   
    for(int i=n-1;i>=0;i--)
    {
        cout<<arr[i];
    }
    

}
