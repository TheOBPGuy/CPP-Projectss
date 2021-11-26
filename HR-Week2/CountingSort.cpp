#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> res(100);
    // Populate the whole array wiht 0
    for (int i = 0 ; i< 100; i++) {
        res[i] = 0;
    }

    for (int i = 0; i < arr.size(); i++) {
        res[arr[i]]++;
    }

    return res;
}

int main() {
    return 0;
}