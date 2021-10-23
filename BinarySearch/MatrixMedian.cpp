#include <iostream>
#include <vector>

using namespace std;

int findKthSmallest(vector<int> A, int B);
int findNearestPossible(vector< vector<int> > A, int num);
int findMedian(vector< vector<int> > A);

// First find the kth Smallest element of an Array
// int findKthSmallest(vector<int> A, int B) {
//     int N = A.size();
//     int lo = 0; int hi = N-1; int mid, next;
//     while (lo <= hi) {
//         mid = lo + (hi-lo)/2;
//         next = (mid+1)%N;
//         if (A[mid] < B) {
//             lo = mid+1;
//         } else if (A[mid] > B) {
//             hi = mid-1;
//         } else {
//             if (A[next] == B) {
//                 lo = mid+1;
//             } else {
//                 return mid+1;
//             }
//         }
//     }
//     return hi+1;
// }

int findKthSmallest(vector<int> A, int B) {
    int N = A.size();
    int lo = 0; int hi = N-1; int mid, next;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        next = (mid+1)%N;
        if (A[mid] <= B) {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return lo;
}

int findMedian(vector< vector<int> > A) {
    int factor = (A.size()*A[0].size())/2;
    cout << factor << "\n";
    int count = 0;
    int lo = 1; int hi = INT_MAX; int mid;

    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        int tempSum = 0;
        for (int i = 0; i < A.size(); i++) {
            tempSum += findKthSmallest(A[i],mid);
        }

        if (tempSum <= factor) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }

        // if (tempSum > factor) {
        //     hi = mid-1;
        // } else if (tempSum < factor) {
        //     lo = mid+1;
        // } else {
        //     cout << tempSum << "," << mid << "   " << lo << "," << hi << "Hello" << "\n";
        //     return mid+1;
        // }
        cout << tempSum << "," << mid << "   " << lo << "," << hi << "\n";
    }

    cout << lo << "," << hi << "\n";

    return lo;
    // return hi+1;
}

int main() {
    vector<int> one = {4};
    vector<int> two = {2};
    vector<int> three = {5};
    vector< vector<int> > A;
    A.push_back(one); 
    A.push_back(two); A.push_back(three);
    findMedian(A);
    return 0;
}