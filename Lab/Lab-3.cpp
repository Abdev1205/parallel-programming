#include <iostream>
#include <omp.h>

using namespace std;

int main() {
  int n = 1000;
  int sum = 0;

// Combined parallel loop reduction
#pragma omp parallel for reduction(+ : sum)
  for (int i = 0; i < n; ++i) {
    sum += i;
  }

  cout << "Combined parallel loop reduction result: " << sum << endl;

  // Orphaned parallel loop reduction
  int partial_sums[omp_get_max_threads()] = {0};

#pragma omp parallel
  {
    int local_sum = 0;

#pragma omp for
    for (int i = 0; i < n; ++i) {
      local_sum += i;
    }

    partial_sums[omp_get_thread_num()] = local_sum;
  }

  // Reduce partial sums
  sum = 0;
  for (int i = 0; i < omp_get_max_threads(); ++i) {
    sum += partial_sums[i];
  }

  cout << "Orphaned parallel loop reduction result: " << sum << endl;

  return 0;
}
