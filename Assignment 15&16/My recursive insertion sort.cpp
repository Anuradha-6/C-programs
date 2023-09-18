#include <iostream>
using namespace std;
void
input (int arr[], int n)
{
  cout << "Enter the array elements";
  for (int i = 0; i < n; i++)
    cin >> arr[i];
}

void
display (int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << "  ";
  cout << "\n";
}

void
recursive_insertion (int arr[], int start, int n)
{
    int x=start;
  if (arr[x] < arr[x- 1] && x>0)
    {
      int key = arr[x];
      arr[x] = arr[x- 1];
      arr[x - 1] = key;
      recursive_insertion(arr,x-1,n);
    }
  if (start < n){
    recursive_insertion (arr, start + 1, n);
  }
}

int
main ()
{
  int n;
  cout << "Enter the size of the array\n";
  cin >> n;
  int arr[n];
  input (arr, n);
  recursive_insertion (arr, 1, n);
  cout << "The sorted array : ";
  display (arr, n);

}
