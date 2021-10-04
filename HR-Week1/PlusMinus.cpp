#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

void plusMinus(vector<int> arr) {
    float positive = 0;
    float negative = 0;
    float zero = 0;

    int N = arr.size();

    if (N <= 0) {
        cout << "Not Possible" << "\n";
        return;
    }

    for (int val : arr) {
        if (val > 0) {
            // Positive
            positive = positive + 1;
        } else if (val < 0) {
            // Negative
            negative = negative + 1;
        } else {
            // Zero
            zero = zero + 1;
        }
    }

    cout << std::fixed;
    cout << std::setprecision(6);
    cout << (float)positive/(float)N << "\n";
    cout << (float)negative/(float)N << "\n";
    cout << (float)zero/(float)N << "\n";
}

int main() {

    vector<int> arr = { 1,1,0,-1,-1 };
    plusMinus(arr);
    return 0;
}