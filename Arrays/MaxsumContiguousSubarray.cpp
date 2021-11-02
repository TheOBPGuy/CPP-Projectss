#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> A) {
    if (A.size() == 0) {
        return 0;
    }
    int current = A[0];
    int maxSum = current;
    for (int i = 1 ; i < A.size(); i++) {
        int tempS = current + A[i];
        current = max(A[i], tempS);
        maxSum = max(current,maxSum);
    }
    return maxSum;
}

int main() {
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
    cout << maxSubArray(A);
    return 0;
}