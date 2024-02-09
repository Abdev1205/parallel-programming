#include <iostream>
#include <omp.h>

using namespace std;

int main() {
  int n = 10;
  int a[n], b[n], c[n];

// Loop work-sharing example
#pragma omp parallel for
  for (int i = 0; i < n; ++i) {
    a[i] = i;
    b[i] = i * 2;
  }

  cout << "Loop work-sharing result:" << endl;
  for (int i = 0; i < n; ++i) {
    c[i] = a[i] + b[i];
    cout << c[i] << " ";
  }
  cout << endl;

// Sections work-sharing example
#pragma omp parallel sections
  {
#pragma omp section
    {
      cout << "Section 1 executed by thread " << omp_get_thread_num() << endl;
      // Perform some work for section 1
    }

#pragma omp section
    {
      cout << "Section 2 executed by thread " << omp_get_thread_num() << endl;
      // Perform some work for section 2
    }
  }

  return 0;
}
