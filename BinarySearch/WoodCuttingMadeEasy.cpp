#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> A, int B) {
    // First we need to fidn the largest and smallest element from the list
    int largest = INT_MIN;
    int smallest = INT_MAX;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > largest) {
            largest = A[i];
        }
        if (A[i] < smallest) {
            smallest = A[i];
        }
    }
    
    vector<int> targets;
    for (int i = smallest; i <= largest; i++) {
        targets.push_back(i);
    }

    int N = targets.size();
    int hi = N-1; int lo = 0; int mid;

    while (lo <= hi) {
        mid = lo + (hi-lo)/2;

        // 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
        int H  = targets[mid];
        int tempSum = 0;
        for (int i = 0; i < A.size(); i++) {
            int s = A[i] - H;
            if (s > 0) {
                // we dont consider the values less than 0
                tempSum += s;
            }
        }
        // cout << tempSum <<  "," << mid << "\n";
        if (tempSum > B) {
            // We have overcrossed our boundaries so we need to move left
            lo = mid+1;
        } else if (tempSum < B){
            hi = mid - 1;
        } else {
            return targets[mid];
        }
    }
    return targets[mid-1];
}

int main() {
    vector<int> A = {4, 42, 40, 26, 46}; int B = 20;
    cout << solve(A,B);
    return 0;
}