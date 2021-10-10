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
    for (int i = 0; i < 26; i++) {
        cout << aArr[i] << ", " ;
    }

    cout << "\n";

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
    //['a','b','c']
    vector<int> queryArr;
    for (int i = 0 ; i < queries.size(); i++) {
        int querySize = queries[i].length();
        int queriesSum = 0;
        for (int j = 0; j < querySize; j++) {
            int val = static_cast<int>(queries[i][j]);
            queriesSum = queriesSum + val;
            // cout << queries[i][j] << "," << val << "\n";
        }
        queryArr.push_back(queriesSum);
    }

    for (int v : queryArr) {
        cout << v << " ";
    }

    cout << "\n";
    // Convert the Strings Arr
    vector<int> stringsArr;
    for (int i = 0; i < strings.size(); i++) {
        int stringSize = strings[i].length();
        int stringsSum = 0;
        for (int j = 0; j< stringSize; j++) {
            int val = static_cast<int>(strings[i][j]);
            stringsSum = stringsSum + val;
        }
        stringsArr.push_back(stringsSum);
    }

    for (int v : stringsArr) {
        cout << v << " ";
    }

    cout << "\n";

    for (int i = 0; i < queryArr.size(); i++) {
        // cout << queryArr[i] << "\n";
        int sum = 0 ;
        for (int j = 0; j < stringsArr.size(); j++) {
            if (queryArr[i] == stringsArr[j]) {
                sum++;
            }
        }
        res.push_back(sum);
    }

    for (int v : res) {
        cout << v << " ";
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
    cout << checkStrings(a, b);

    return 0;
}