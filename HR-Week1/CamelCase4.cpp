#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

string fillString(char arr[], int start, int end);
void camelCase4(vector<string> arr);

string fillString(char arr[], int start, int end) {
    string res = "";
    // Check for first case conditions
    if (end == -1) {
        return "";
    }

    for (int i = start; i <= end; i++) {
        res += arr[i];
    }

    return res;
}

void camelCase4(vector<string> arr) {
    // First handle case wiht Split Operation:
    int N = arr.size();
    for (int i = 0; i < N; i++) {
        string current = arr[i];
        string delimeter = ";";
        string first = current.substr(0,current.find(delimeter));
        if (first == "S") {
            // Split Operation
            // iterate through the string:
            string temp = current.substr(4,current.size());
            int strLen = temp.size();
            char charArr[strLen]; 
            string tmp = "";
            int start, end = 0;
            for (int j = 0; j < strLen; j++) {
                // Check if non-string data is being passed into the argument
                if (temp[j] == '(' || temp[j] == ')') {
                    continue;
                } else {
                    if (isupper(temp[j])) {
                        if (j != 0) {
                            // Check for first time case
                            tmp = tmp + " ";
                        }
                        string s(1,tolower(temp[j]));
                        tmp += s;
                    } else {
                        tmp = tmp + temp[j];
                    }
                }
            }
            // string res(charArr);
            cout << tmp << "\n";
        } else {
            if (first == "C") {
                
                // There can be 3 types of cases here:
                string type = current.substr(2,2);
                string tmp = "";
                string temp = current.substr(4,current.size());
                bool checkFirst = false;
                if (type == "V;") {
                    
                    for (int j = 0; j < temp.size(); j++) {
                        if (temp[j] != ' ') {
                            if (!checkFirst) {
                                tmp += temp[j];
                            } else {
                                checkFirst = !checkFirst;
                                char c = toupper(temp[j]);
                                tmp += c;
                            }
                            
                        } else {
                            checkFirst = true;
                        }
                    }
                    cout << tmp << "\n";
                } else if (type == "C;") {
                    // We are looking at a Class Name now
                    // The first letter should be capitalized

                    for (int j = 0; j < temp.size(); j++) {
                        if (j == 0) {
                            char c = toupper(temp[j]);
                            tmp += c;
                        } else {
                            if (temp[j] != ' ') {
                                if (!checkFirst) {
                                    tmp += temp[j];
                                } else {
                                    checkFirst = !checkFirst;
                                    char c = toupper(temp[j]);
                                    tmp += c;
                                }
                            }
                             else {
                                checkFirst = true;
                            }
                        }
                        
                    }
                    cout << tmp << "\n";
                } else {
                    // We are looking at a method here:
                    for (int j = 0; j < temp.size(); j++) {
                        if (temp[j] != ' ') {
                            if (!checkFirst) {
                                tmp += temp[j];
                            } else {
                                checkFirst = !checkFirst;
                                char c = toupper(temp[j]);
                                tmp += c;
                            }
                            
                        } else {
                            checkFirst = true;
                        }
                    }
                    tmp += "()";
                    cout << tmp << "\n";
                }
            }
        }
    }
}

int main() {
    vector<string> arr;
    string s1;

    // int count;
    // cin >> count;
    // for (int k = 0; k < count+1; k++) {
    //     // cout << "Hello";
    //     char s[30] = {0};
    //     cin.getline(s,30);
    //     // string ss(s);
    //     // cout << ss;
    //     arr.push_back(s);
    // }

    bool condition = true;
    while (condition) {
        char s[30] = {0};
        cin.getline(s,30);
        string xx(s);
        if (xx.empty()) {
            condition = !condition;
            break;
        } else {
            arr.push_back(xx);
        }
    }
    //arr.push_back(s);

    camelCase4(arr);

    // // Display the strings now
    // for (int i  = 0; i < count; i++) {
    //     cout << arr[i];
    // }

    return 0;
}