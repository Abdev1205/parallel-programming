#include <iostream>
#include <omp.h>

using namespace std;

#define ARRAY_SIZE 10000

int main()
{
  int array[ARRAY_SIZE];
  int sum = 0;

  // Initialize array
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    array[i] = i + 1;
  }

#pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < ARRAY_SIZE; ++i)
  {
    sum += array[i];
  }

  cout << "Sum of array elements: " << sum << endl;

  return 0;
}
