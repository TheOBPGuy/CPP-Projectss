#include <iostream>

using namespace std;

bool isPrime(long long int N);

long long int solve(long long int num) {
    long long int res = INT_MIN;
    // Iterate backwards
    for (long long int i = num-1 ; i >= 1; i--) {
        if (num % i == 0) {
            cout << i << "\n";
            if (isPrime(i)) {
                res = max(i, res);
                return res;
            }
        }
    }
    return res;
}

bool isPrime(long long int N) {
    if (N <= 1) { return false; }
    for (int i = 2; i*i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long int num = 600851475143;
    cout << solve(num);
    return 0;
}