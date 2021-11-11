#include <iostream>
#include <vector>
#define mod 10000003

using namespace std;

// Dynamic Programming Solution
long long int solve(long long int range) {
    long long int dp[range+2];
    dp[0] = 0;
    dp[1] = 1;

    long long int res = 0;

    for (int i = 2; i <= range; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%mod;

        // Check if number is even:
        if (dp[i] % 2 == 0) {
            res = (res + dp[i])%mod;
        }
    }
    long long int N = sizeof(dp)/sizeof(dp[0]);

    return res;
}

int main() {
    long long int range = 400000;
    long long int r = range%mod;
    cout << solve(r);
    return 0;
}