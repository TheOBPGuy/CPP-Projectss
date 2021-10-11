#include <iostream>
#include <vector>

using namespace std;

int divisibleSumPairs(int n, int k, vector<int> ar) {
    int res = 0;
    for (int i = 0; i < ar.size(); i++) {
        for (int j = i+1; j < ar.size(); j++) {
            int num1 = ar[i];
            int num2 = ar[j];
            // cout << "[" << num1 << "," << num2 << "]" << "\n";

            // check 2 conditions:
            // 1. j < j -> this will automatically be true
            // 2. ar[i] + ar[j] % 5 == 0

            int checkSum = ar[i] + ar[j];
            if (checkSum % k== 0) {
                res++;
            }

        }
    }

    return res;
}

int main() {

    vector<int> ar = {1,3, 2, 6, 1, 2};
    int n = ar.size();
    int k = 3;

    cout << divisibleSumPairs(n,k,ar);

    return 0;
}