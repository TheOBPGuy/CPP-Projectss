#include <iostream>
#include <algorithm>

using namespace std;

void recurse(string A, int B, string ans) {
    // Base Condition:
    if (B == 0) {
        // Conver both A and ans to numbers.
        int ori = stoi(A);
        int ansInt = stoi(ans);
        if (ansInt > ori) {
            ansInt = ori;
        }
    }

    // Recurive Calls using Backtracking
    for (int i = 0; i < A.size(); i++) {
        for (int j = i+1; j < A.size(); j++) {
            // Swap the index values
            swapStrings(A,i,j);
            // Make the recurive calls
            recurse(A, B-1, ans);
            // Restore the version of the swaped index;
            swapStrings(A, i, j);
        }
    }

}

void swapStrings(string A, int start, int end) {
    swap(A[start], A[end]);
}

int solve(string A, int B) {
    string ans = "";
    recurse(A, B, ans);
    return ans;
}

int main() {
    return 0;
}