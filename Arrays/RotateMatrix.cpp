#include <iostream>
#include <vector>

using namespace std;

void rotate(vector< vector<int> > A) {
    // 1. Transpose the matrix -> O(N^2)
    // 2. Reverse the transposed matrix -> O(N^2)
    for (int i = 0; i < A.size(); i++) {
        for (int j = i; j < A[i].size(); j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    int N = A.size();
    // Reverse the transposed martrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (N/2); j++) {
            int temp = A[i][j];
            A[i][j] = A[i][N-1-j];
            A[i][N-1-j] = temp;
        }
    }
}

int main() {
    return 0;
}