#include <iostream>
#include <stack>

using namespace std;

int solve(string A) {
    stack<char> open;
    // Fill the stack at first depending on 
    // opening or closing brackets
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '(') {
            // Open brackets
            open.push(A[i]);
        } else {
            // First check if the stack is alredy made empty or not
            if (!open.empty()) {
                char close = open.top();
                if (A[i] == ')' && close == '(') {
                    open.pop();
                    continue;
                }
            }
            else {
                return 0;
            }
        }
    }

    if (!open.empty()) {
        return 0;
    }

    return 1;

}

int main() {
    // string A = "(()";

    string A = "()()(((())()))))()(()(()((()(()((()()((())((())(()()()()())())()(((()(()(";
    cout << solve(A);
    return 0;
}