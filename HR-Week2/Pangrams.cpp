#include <iostream>
#include <vector>
#include <string>

using namespace std;

string pangrams(string s) {
    vector<int> alpha(26);

    // Fill the vector with -1;
    for (int i = 0 ; i < alpha.size(); i++) {
        alpha[i] = -1;
    }

    for (int i = 0 ; i < s.size(); i++) {
        if (s[i] == ' ') {
            // check for empty string
            continue;
        } else {
            char c = tolower(s[i]);
            alpha[c-'a']++;
        }
    }

    for (int i = 0; i < alpha.size(); i++) {
        if (alpha[i] == -1) {
            return "not pangram";
        }
    }
    return "pangram";

}

int main() {
    char input[100] = {0};
    cin.getline(input,100);
    string s(input);
    
    cout << pangrams(s);
    return 0;
}