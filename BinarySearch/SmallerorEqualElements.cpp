#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> A, int B) {

    int N = A.size();
    int lo = 0; int hi = N-1;
    int next, mid;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        next = (mid+1)%N;
        if (A[mid] < B) {
            lo = mid+1;
        } else if (A[mid] > B) {
            hi = mid-1;
        } else {
            if (A[next] == B) {
                lo = mid+1;
            } else {
                return mid+1;
            }
        }
    }

    return hi+1;
}

int main() {
    vector<int> A = {1, 2, 5, 5}; int B = 3;
    cout << solve(A,B);
    return 0;
}