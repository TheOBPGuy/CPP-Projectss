#include <iostream>
#include <vector>

using namespace std;

int birthday(vector<int> s, int d, int m) {
    int t = 0;
    for (int i = 0; i <= s.size()-m; i++) {
        int sum = 0;
        for (int j = i; j < m+i; j++) {
            sum += s[j];
        }
        if (sum == d) {
            t++;
        }
    }
    return t;
}

int main() {
    int d = 4;
    int m = 2;
    vector<int> s = {2,2,1,3,2};
    cout << birthday(s,d,m);
    return 0;
}