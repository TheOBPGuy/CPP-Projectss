#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> A, int num, int mid);
int books(vector<int> A, int B);

bool isPossible(vector<int> A, int num, int mid) {
    int newSum = 1;
    int tempSum = 0;
    for (int i = 0 ; i< A.size(); i++) {
        tempSum += A[i];
        if (tempSum > mid) {
            // If we are crossing the mid then we need to allocate to another student
            newSum++;
            tempSum = 0;
            i--;
        }
    }
    // If we crossed over the 
    if (newSum > num) {
        return false;
    } else {
        return true;
    }
}

int books(vector<int> A, int B) {
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
    vector<int> A = {73, 58, 30, 72, 44, 78, 23, 9};
    int B = 5;
    cout << "\n";
    cout << books(A,B);
    return 0;
}