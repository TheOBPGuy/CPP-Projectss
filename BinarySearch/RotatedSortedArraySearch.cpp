#include <iostream>
#include <vector>

using namespace std;

//int search(vector<int> A, int B) { 
//     int N = A.size();
//     int lo = 0, hi = N-1;
//     int mid, prev, next;

//     while (lo <= hi) {
//         mid = lo + (hi-lo)/2;
//         prev = (mid-1)%N;
//         next = (mid+1)%N;

//         if (A[mid] < A[hi]) {
//             hi = mid-1;
//         } else {
//             lo = mid+1;
//         }
//     }

//     int start = lo-1;
//     cout << lo << "\n";
//     int lo2 = 0; int hi2 = N-1;
//     if (B <= A[hi2] and B >= A[lo2]) {
//         lo2 = start;
//     } else {
//         hi2 = start;
//     }
//     cout << lo2 << "," << hi2 << "\n";
//     int mid2;
//     while (lo2 <= hi2) {
//         mid2 = lo2 + (hi2-lo2)/2;
//         if (B < A[mid2]) {
//             hi2 = mid2-1;
//         } else if (B > A[mid2]) {
//             lo2 = mid2+1;
//         } else {
//             return mid2;
//         }
//     }
//     return -1;

// } 

int search(vector<int> A, int B) {
    int N = A.size();
    int lo = 0, hi = N-1; int mid;

    while (lo <= hi) {
        // Do a regular binary Search here
        mid = lo + (hi-lo)/2;

        if (A[mid] == B) {
            return mid;
        }

        if (A[mid] > A[lo]) {
            if (A[lo] <= B and B <= A[mid]) {
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        } else {
            if (A[mid] <= B and B <= A[hi]) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    // 0 1 2 3 4 5 6 7
    // 1 2 3 4 5 6 7 0
    // 4 5 6 7 0 1 2 3
    vector<int> A = {4, 5, 6, 7, 0, 1, 2, 3}; 
    // vector<int> A = {1, 2, 3, 4, 5, 6, 7, 0}; 
    int B = 4;
    cout << search(A,B);
    return 0;
}