#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int checkMax(queue<int> qu);

/**
 * @brief 
 * Given an array of integers A.  There is a sliding window of size B which 
 * is moving from the very left of the array to the very right. 
 * You can only see the w numbers in the window. Each time the sliding window moves 
 * rightwards by one position. You have to find the maximum for each window. 
 * The following example will give you more clarity.
 * 
 * @param A 
 * @param B 
 * @return vector<int> 
 */
vector<int> slidingMaximum(vector<int> A, int B) {
    int maxE = INT_MIN;
    queue<int> qu;
    vector<int> res;
    // Check initial condition
    if (B > A.size()) {
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
        // maxE = max(maxE, A[i]);
        // Enqueue queue
        qu.push(A[i]);
        // Dequeue queue
        qu.pop();

        // Find the new Maximum on the queue
        maxE = checkMax(qu);

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

int checkMax(queue<int> qu) {
    int newMax = INT_MIN;
    queue<int> temp = qu;
    for (int i = 0; temp.size(); i++) {
        newMax = max(newMax, temp.front());
        temp.pop();
    }
    return newMax;
}

int main() {
    vector<int> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; int B = 2;
    vector<int> res = slidingMaximum(A, B);

    printVector(res);
    return 0;
}