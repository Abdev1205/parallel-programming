#include <iostream>
#include <omp.h>

using namespace std;

const int N = 100;         // Reduced size of the matrices for testing
const int CHUNK_SIZE = 16; // Size of chunks for chunked matrix multiplication

// Function to perform matrix multiplication
void matrixMultiply(int A[N][N], int B[N][N], int C[N][N]) {
#pragma omp target teams distribute parallel for collapse(2) map(to : A, B)    \
    map(from : C)
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main() {
  int A[N][N], B[N][N], C[N][N];

// Initialize matrices A and B
#pragma omp parallel for collapse(2)
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      A[i][j] = i + j;
      B[i][j] = i - j;
      C[i][j] = 0;
    }
  }

  cout << "Matrices initialized." << endl;

  // Perform matrix multiplication
  cout << "Performing matrix multiplication..." << endl;
  matrixMultiply(A, B, C);
  cout << "Matrix multiplication completed." << endl;

  // Output the result (print a small portion for demonstration)
  cout << "Result Matrix (partial):" << endl;
  for (int i = 0; i < min(N, 5); ++i) {
    for (int j = 0; j < min(N, 5); ++j) {
      cout << C[i][j] << " ";
    }
    cout << endl;
  }
  if (N > 5) {
    cout << "..." << endl;
  }

  return 0;
}
