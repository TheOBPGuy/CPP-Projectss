#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> A, int num, int mid);
int books(vector<int> A, int B);

bool isPossible(vector<int> A, int students, int mid) {
    int newStudents = 1;
    int tempSum = 0;
    for (int i = 0 ; i< A.size(); i++) {
        if (A[i] > mid) {
            return false;
        }
        if (tempSum + A[i] > mid) {
            newStudents++;
            tempSum = A[i];
        } else {
            tempSum += A[i];
        }
    }
    // If we crossed over the 
    if (newStudents > students) {
        return false;
    } else {
        return true;
    }
}

int books(vector<int> A, int B) {
    // 0. First initial check
    if (B > A.size()) {
        return -1;
    }
    
    // 1. find the lowest possible and highest possible pages
    int lo = INT_MAX; int hi = 0;
    for (int i = 0 ; i < A.size(); i++) {
        lo = min(lo, A[i]);
        hi += A[i];
    }

    int res = 0;

    cout << lo << "," << hi << "\n";
    int mid;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        // 2. Iterate from start. check how many books can be alloted
        // to student without crossing the 
        cout << mid << "\n";
        if (isPossible(A,B,mid)) {
            hi = mid-1;
            res = mid;
        } else {
            lo = mid+1;
        }
    }

    return res;
}

int main() {
    // vector<int> A = {12, 34, 67, 90};
    vector<int> A = {97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24};
    int B = 26;
    cout << "\n";
    cout << books(A,B);
    return 0;
}