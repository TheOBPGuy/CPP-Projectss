#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num);

int solve(int A, int B) {
    // Find number of prime numbers in A range
    int total_primes_in_A = 0;
    int total_primes_in_B = 0;

    for (int i = 0; i < A; i++) {
        if (isPrime(i)) {
            total_primes_in_A++;
        }
    }

    for (int i = 0; i < B; i++) {
        if (isPrime(i)) {
            total_primes_in_B++;
        }
    }

    int res = max(total_primes_in_A, total_primes_in_B) - 
    min(total_primes_in_B, total_primes_in_A);

    return res;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int A = 100; int B = 90;
    cout << solve(A,B);
    return 0;
}