#include <iostream>
using namespace std;

int main()
{
  int arr[10000];
  int sum = 0;
  for (int i = 0; i < 10000; i++)
  {
    arr[i] = i + 1;
  }

  for (int i = 0; i < 10000; i++)
  {
    sum += arr[i];
  }
  cout << "Sum of array elements: " << sum << endl;

  return 0;
}
