#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> slidingMaximum(vector<int> A, int B) {
    int maxE = INT_MIN;
    queue<int> qu;
    vector<int> res;
    // Check initial condition
    if (B >= A.size()) {
        res.push_back(1);
        return res;
    }

    // Step 2: Fill in the initial values while keeping track of Maximum
    for (int i = 0; i < B; i++) {
        maxE = max(maxE, A[i]);
        // Enqueue queue
        qu.push(A[i]);
    }
    res.push_back(maxE);
    // Step 3: Iterate from the remainder of the items
    // starting from where we left off
    for (int i = B; i < A.size(); i++) {
        maxE = max(maxE, A[i]);
        // Enqueue queue
        qu.push(A[i]);
        // Dequeue queue
        qu.pop();

        // Step 4: Record the maximum
        res.push_back(maxE);
    }

    return res;
}

void printVector(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << ",";
    }
}

int main() {
    vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7}; int B = 3;
    vector<int> res = slidingMaximum(A, B);

    printVector(res);
    return 0;
}