#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> A, int num) {

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
    }

    return -1;
}

int main() {
    vector<int> A = {12, 34, 67, 90};
    // vector<int> A = {73, 58, 30, 72, 44, 78, 23, 9};
    int B = 2;
    cout << "\n";
    cout << books(A,B);
    return 0;
}