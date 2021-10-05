#include <iostream>
#include <string>

using namespace std;

string timeConversion(string s) {
    // Check for AM vs PM
    bool isAM = false;
    int N = s.length();
    string sAMvsPM = s.substr(N-2,N);
    if (sAMvsPM == "AM") {
        isAM = true;
    }

    string newstr = "";

    string delimeter = ":";
    string first = s.substr(0,s.find(delimeter));
    if (isAM) {
        if (first == "12") {
            string remainder = s.substr(2,N);
            newstr = "00" + remainder;
            newstr = newstr.substr(0,N-2);
            // cout << newstr;
            // return newstr;
        } else {
            cout << N << "\n";
            newstr = s.substr(0,N-2);

            // return newstr;
        }
        
    } else {
        // cout << "PM";
        int firstNum = stoi(first);
        if (firstNum == 12) {
            newstr = s.substr(0,N-2);
            // return newstr;
        } else {
            firstNum = firstNum + 12;
            // cout << N << "\n";
            // cout << s.substr(2,6) << "\n";
            newstr = to_string(firstNum) + s.substr(2,N-4);
            // return newstr;
        }
    }


    return newstr;
}

int main() {
    string s = "06:40:03AM";
    cout << timeConversion(s);
    return 0;
}