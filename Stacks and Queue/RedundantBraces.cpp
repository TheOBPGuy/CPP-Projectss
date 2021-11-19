#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief (a+(a+b))
 * 
 * Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
 * Chech whether A has redundant braces or not.
 * Return 1 if A has redundant braces, else return 0.
 * Note: A will be always a valid expression.
 * 
 * @param A 
 * @return int 
 */
int braces(string A) {
    stack<int> st;
    
    for (int i = 0; i < A.size(); i++) {
        // if its the first opening bracket 
        if (A[i] == ')') {
            int count = 0;
            while (!st.empty() and st.top() != '(') {
                count++;
                st.pop();
            }
            if (count <= 1) {
                return 1;
            }
            st.pop();

        } else {
            st.push(A[i]);
        }
    }
    return 0;
}

int main() {
    return 0;
}