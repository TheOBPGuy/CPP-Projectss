#include <iostream>
#include <vector>

using namespace std;

// First Approach:
// Here we will create another array and iterate through the matrix
// Store the values of the matrix onto a second vector
// And finally run binary search on that vector
int searchMatrixOne(vector< vector<int> > A, int B) {
    int N = A.size(); int M = A[0].size();

    // Copy over the matrix onto a second vector
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr.push_back(A[i][j]);
        }
    }

    int size = arr.size();
    int lo = 0; int hi = size-1; int mid;

    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        if (arr[mid] < B) {
            lo = mid + 1;
        } else if (arr[mid] > B) {
            hi = mid-1;
        } else {
            return 1;
        }
    }
    return 0;
}

int main() {
    return 0;
}