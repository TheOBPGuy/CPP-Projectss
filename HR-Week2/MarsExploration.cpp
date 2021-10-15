#include <iostream>
#include <string>
#include <vector>

using namespace std;

int marsExploration(string s) {
    int size = s.size();
    int tot = size/3;

    // First create the EXPECTED String array
    string expected = "";
    bool isS = true;
    bool isO = false;
    int count = 0;
    for (unsigned int i = 0; i < size; i++) {
        if (isS) {
            expected += "S";
            count++;
            isS = false;
            if (count == 3) {
                // We have completed one SOS
                isS = true;
                count = 0;
            }
        } else {
            expected += "O";
            isS = true;
            count++;
        }
    }

    // Iterate over the second string now
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != expected[i]) {
            c++;
        }
    }

    cout << expected;
    cout << "\n";
    return c;
}

int main(){
    // char input[100] = {0};
    // cin.getline(input,100);
    // string s(input);
    string s = "SOSSPSSQSSOR";
    cout << marsExploration(s);
    return 0;
}