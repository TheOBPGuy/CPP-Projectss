#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> prevSmaller(vector<int> A) {
    vector<int> res;
    int maxE = INT_MIN;
    stack<int> st;

    for (int i = 0; i < A.size(); i++) {
        maxE = max(maxE, A[i]);
        while (!st.empty()) {
            if (st.top() >= A[i]) {
                // Pop the element until you get a value lower than the
                // Current A[i] value
                st.pop();
            } else {
                res.push_back(st.top());
                break;
            }
        }

        if (st.empty()) {
            res.push_back(-1);
        }

        // Insert the current element onto the stack
        st.push(A[i]);
    }

    return res;
}

void printV(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << ",";
    }
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> res = prevSmaller(A);

    printV(res);
    return 0;
}