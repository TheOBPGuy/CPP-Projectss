// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>

// string ltrim(const string &);
// string rtrim(const string &);
// vector<string> split(const string &);


using namespace std;

int sockMerchant(int n, vector<int> ar) {
    int res = 0;
    unordered_map<int, int> map;
    for (unsigned int i = 0; i < ar.size(); i++) {
        auto temp = map.find(ar[i]);
        if (temp != map.end()) {
            // if the element is not already on the map
            temp->second++;
        } else {
            // We need to put a new entry onto the map
            map.insert({ar[i],1});
        }
    }

    // Extract all the elements from the map one by one 
    // then check to see if they are divisible by 2
    for (const auto &val : map) {
        cout << val.first << "," << val.second << "\n";
        int check = val.second;
        res += check /2 ;
        // if (check  2 == 0) {
        //     res++;
        // }
    }
    return res;
}

int main() {
    // ofstream fout(getenv("OUTPUT_PATH"));

    // string n_temp;
    // getline(cin, n_temp);

    // int n = stoi(ltrim(rtrim(n_temp)));

    // string ar_temp_temp;
    // getline(cin, ar_temp_temp);

    // vector<string> ar_temp = split(rtrim(ar_temp_temp));

    // vector<int> ar(n);

    // for (int i = 0; i < n; i++) {
    //     int ar_item = stoi(ar_temp[i]);

    //     ar[i] = ar_item;
    // }

    int n = 7;
    vector<int> ar = {1,2,1,2,1,3,2};

    int result = sockMerchant(n, ar);
    cout << result;

    return 0;
}