#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> A, vector<int> B) {
    // 1 2 3 4 5
    // 2 3
    // 1 4 5
    if (B.size() < A.size()) {
        // We need to use the smaller Array to get the partition
        return findMedianSortedArrays(B,A);
    }
    int n1 = A.size(), n2 = B.size();
    int lo = 0, hi = n1;

    while (lo <= hi) {
        int cut1 = lo+(hi-lo)/2;
        int cut2 = ((n1+n2+1)/2) - cut1;

        int left1 = cut1 == 0 ? INT_MIN : A[cut1-1];
        int left2 = cut2 == 0 ? INT_MIN : B[cut2-1];

        int right1 = cut1 == n1 ? INT_MAX : A[cut1];
        int right2 = cut2 == n2 ? INT_MAX : B[cut2];

        if (left1 > right2) {
            hi = cut1-1;
        } else if (left2 > right1) {
            lo = cut1+1;
        } else {
            return (n1+n2)%2 == 0 ? (max(left1, left2) + min(right1, right2))/2 : max(left1,left2);
        }
    }
    return 0.0;
}

int main() {
    vector<int> A = {2,3}; vector<int> B = {1,4,5};
    cout << findMedianSortedArrays(A,B);
    return 0;
}