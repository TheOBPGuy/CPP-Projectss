#include <iostream>
#include <vector>

using namespace std;

int maxArr(vector<int> A) {
    int currentSum = 0;
    int maxSum = INT_MIN;
    // 1 3 -1
    for (int i = 0; i < A.size(); i++) {
        int func = 0;
        if (i == 0) {
            // We are looking at the first entry 
            currentSum = 0;
            
        } else {
            currentSum = abs(A[i]-A[i-1]) + abs(i-(i-1));
            
        }
        maxSum = max(maxSum,currentSum);
    }
    return maxSum;
}

int main() {
    vector<int> A = {2,2,2};
    cout << maxArr(A);
    return 0;
}