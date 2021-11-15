#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

string simplifyPath(string A) {
    stack<string> st;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '/') {
            continue;
        } else if (A[i] == '.') {
            // continue looping until 2 matches are found
            // if more than 2 then simply store that as a
            // regular string
            string dots = "";
            int count = 0;
            int idx = i;
            while (true) {
                if (A[i] == '.') {
                    count++;
                    string s(1,A[i]);
                    dots += s;
                }
                if (A[i] != '.') {
                    break;
                }
                idx++;
            }
            if (count > 2) {
                // store the repeated dots as a regular string now
                st.push(dots);
            } else if (count == 2) {
                st.pop();
            } else {
                continue;
            }
        } else {
            string s(1,A[i]);
            if (isalpha(A[i])) {
                while (true) {
                    
                }
                st.push(s);
            }
        }
    }

    // Iterate through the stack until its not empty and print all 
    // the characters one after another
    string res = "";
    while (!st.empty()) {
        string current = st.top();
        res += "/";
        res += current;
        st.pop();
    }

    return res;
}

int main() {
    string A = ""
    return 0;
}