#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Method declarations:
bool checkStrings(string a, string b);
vector<int> matchingStrings(vector<string> strings, vector<string> queries);
int asciiSum(string s);


bool checkStrings(string a, string b) {
    // Create a character Array of a at first
    int aArr[26] = {0};
    for (int i = 0 ; i < a.length(); i++) {
        aArr[a[i]-'a']++;
    }

    // Iterate through string b and check for the following conditions:
    // 1. if all the aArr is filled with 0 in the end --> we have an anagram
    // 2. If there are any more characters left, then its NOT an anagram
    // 3. If we go below 0 -> then its also not an anagram

    for (int i = 0; i < b.length(); i++) {
        aArr[b[i]-'a']--;
    }

    // Make the 2 final checks
    // Iterate through aArr and ensure all are 0;
    for (int i =0; i < 26; i++) {
        if (aArr[i] != 0) {
            return false;
        }
    }

    // Print the char arr to confirm everything looks good
    // for (int i = 0; i < 26; i++) {
    //     cout << aArr[i] << ", " ;
    // }

    // cout << "\n";

    return true;
}

int asciiSum(string s) {
    int res = 0; 
    for (int j = 0; j < s.length(); j++) {
        int val = static_cast<int>(s[j]);
        res = res + val;
        // cout << queries[i][j] << "," << val << "\n";
    }
    return res;
}

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    
    vector<int> res;
    for (int i = 0; i < queries.size(); i++) {
        string queryString = queries[i];
        int count = 0;
        for (int j = 0; j < strings.size(); j++) {
            string stringsString = strings[j];
            if (checkStrings(queryString,stringsString)) {
                count++;
            }
        }
        res.push_back(count);
    }

    for (int k = 0; k < res.size(); k++) {
        cout << res[k];
    }

    return res;
}

int main() {
    // vector<string> strings = {"abc"};
    vector<string> strings = {"abcde","sdaklfj","asdjf","na","basdn","sdaklfj","asdjf","na","asdjf","na","basdn",
        "sdaklfj","asdjf"};
    vector<string> queries = {"abcde","sdaklfj","asdjf","na","basdn"};

    //matchingStrings(strings, queries);
    string a = "abc";
    string b = "abc";
    // cout << checkStrings(a, b);


    matchingStrings(strings, queries);

    return 0;
}