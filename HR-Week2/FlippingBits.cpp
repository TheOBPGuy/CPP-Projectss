#include <iostream>
#include <vector>
#include <string>

using namespace std;

long flippingBits(long n) {
    string first = bitset<32>(n).to_string();

    // for (int i = 0; i < first.size(); i++) {
    //     cout << first[i];
    // }

    // Convert the string by flipping the bits now
    string second = "";
    for (unsigned int i = 0; i < first.size(); i++) {
        char temp = first[i];
        string s(1,temp);
        if (s == "1") {
            // we need to make this a 0;
            s = "0";
        } else {
            // we need to make this a 1;
            s = "1";
        }
        second = second + s;
    }

    // cout << "\n";
    // for (int i = 0; i < second.size(); i++) {
    //     cout << second[i];
    // }

    // Finally convert this string value to a binary value represented in long
    unsigned long res = bitset<32>(second).to_ullong();

    return res;
}

int main() {
    int count;
    cin >> count;
    vector<long> result;
    for (int i = 0; i < count; i++) {
        long n;
        cin >> n;
        unsigned long res = flippingBits(n);
        result.push_back(res);
    }

    for (int j =0; j< count; j++) {
        cout << result[j];
        cout << "\n";
    }

}