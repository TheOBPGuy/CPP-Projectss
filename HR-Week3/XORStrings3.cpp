#include <iostream>
#include <string>

using namespace std;

string strings_xor(string s, string t) {
    string res = "";
    int size = s.size();
    for (int i = 0; i < size; i++) {
        if (s[i] == '0' && t[i] == '0') {
            res += "0";
        } else if (s[i] == '0' && t[i] == '1') {
            res += "1";
        } else if (s[i] == '1' && t[i] == '0') {
            res += "1"; 
        } else {
            res += "0";
        }
    }
    return res;
}

int main() {
    cout << "Hello";
    return 0;
}