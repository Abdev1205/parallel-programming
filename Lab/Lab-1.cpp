#include <iostream>
#include <omp.h>
#include <vector>


using namespace std;

// Function to perform vector addition using OpenMP
vector<int> vectorAddition(const vector<int> &a, const vector<int> &b) {
  int n = a.size();
  vector<int> result(n);

#pragma omp parallel for
  for (int i = 0; i < n; ++i) {
    result[i] = a[i] + b[i];
  }

  return result;
}

// Function to perform dot product calculation using OpenMP
int dotProduct(const vector<int> &a, const vector<int> &b) {
  int n = a.size();
  int result = 0;

#pragma omp parallel for reduction(+ : result)
  for (int i = 0; i < n; ++i) {
    result += a[i] * b[i];
  }

  return result;
}

int main() {
  vector<int> vector1 = {1, 2, 3, 4, 5};
  vector<int> vector2 = {6, 7, 8, 9, 10};

  // Vector addition
  vector<int> sum = vectorAddition(vector1, vector2);
  cout << "Vector Addition Result:";
  for (int val : sum) {
    cout << " " << val;
  }
  cout << endl;

  // Dot product
  int dotProd = dotProduct(vector1, vector2);
  cout << "Dot Product Result: " << dotProd << endl;

  return 0;
}
