#include <iostream>
#include <vector>

using namespace std;

int sqrt(int A) {
    // 1,2,3,4,5,6,7,8,9,10,11
    int lo = 1; int hi = A; long long mid;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;

        long long factor = mid*mid;
        cout << mid << "," << factor << "\n";
        if (factor > A) {
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    return hi;
}

int main() {
    int A = 2147483647;
    cout << sqrt(A);
    return 0;
}