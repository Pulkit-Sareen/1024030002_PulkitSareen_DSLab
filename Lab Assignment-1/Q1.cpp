#include <iostream>
using namespace std;

int n, arr[100];

void create()
{
  cout << "enter the size of the array:";
  cin >> n;
  cout << "Enter the elements of the array";

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << endl;
}
void display()
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void insert()
{
  int index, value;
  cout << "Enter the index:";
  cin >> index;
  cout << "Enter the value to be inserted";
  cin >> value;
  for (int i = n; i > index; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[index] = value; 
  n++;
  cout << endl;
}
void deleteElement()
{
  int position;
  cout << "Enter the position of the element to be deleted";
  cin >> position;
  for (int i = position; i < n - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  n--;
  cout << endl;
}
void linearSearch()
{
  int search;
  cout << "enter the element to be searched";
  cin >> search;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == search)
    {
      cout << "the element was found at index: " << i << endl;
      return;
    }
  }
  cout << "element not found\n";
}

int main()
{
  int a;
  while (true)
  {
    cout << "\n<-----Menu----->" << endl;
    cout << "1.Create   ";
    cout << "2.Display  ";
    cout << "3.Insert   ";
    cout << "4.Delete an element   ";
    cout << "5.Linear search   ";
    cout << "6.Exit   "<<endl;
    cout << "Enter the value of a" << endl;
    cin >> a;

    switch (a)
    {
    case 1:
      create();
      break;
    case 2:
      display();
      break;
    case 3:
      insert();
      break;
    case 4:
      deleteElement();
      break;
    case 5:
      linearSearch();
      break;
    case 6:
      exit(0);
    default:
      cout << "invalid choice!";
    }
  }
}
