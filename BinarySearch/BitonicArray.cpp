#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> A, int B) {
     int N = A.size();
     int lo = 0; int hi = N-1;
     int prev, next, mid;

     while (lo <= hi) {
         mid = lo + (hi - lo)/2;
         prev = (mid-1)%N;
         next = (mid+1)%N;
         if (A[prev] <= A[mid] and A[mid] <= A[next]) {
             // we need to move left or right depending 
             // where mid is compared to the rest of the target
             if (A[mid] < B) {
                 lo = mid+1;
             } else if (A[mid] > B) {
                 hi = mid-1;
             } else {
                 return mid;
             }
         } else if (A[mid] <= A[prev] and A[mid] >= A[next]) {
             // A = [5, 6, 7, 8, 9, 10, 3, 2, 1]
             // if A[mid] greater than B -> move high
             // else move lo
             if (A[mid] > B) {
                 // We need to keep moving right in this case
                lo = mid + 1;
             } else if (A[mid] < B) {
                 hi = mid - 1;
             } else {
                 return mid;
             }
         } else {
             // left is small and right is small
             if (A[mid] == B) {
                return mid;
             } else {
                 return -1;
             }
         }
     }
     return -1;
}

int main() {
    vector<int> A = {5, 6, 7, 8, 9, 10, 3, 2, 1}; int B = 30;
    cout << solve(A, B);
    return 0;
}