#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool checkA(vector<int> a, int val);
bool checkB(vector<int> b, int val);

int getTotalX(vector<int> a, vector<int> b) {
    // first get the last element of b;
    
    if (a.empty() && b.empty()) {
        return 0;
    }

    int lastB = b[b.size()-1];

    int res = 0;
    for (int i = 2; i <= lastB; i++) {
        if (checkA(a,i) && checkB(b,i)) {
            res++;
        }
    }
    return res;
}

bool checkA(vector<int> a, int val) {
    for (int i = 0; i < a.size(); i++) {
        if (val % a[i] != 0) {
            return false;
        }
    }
    return true;
}

bool checkB(vector<int> b, int val) {
    for (int i = 0; i < b.size(); i++) {
        if (b[i] % val != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    return 0;

//     2 3
// 2 4
// 16 32 96 
}