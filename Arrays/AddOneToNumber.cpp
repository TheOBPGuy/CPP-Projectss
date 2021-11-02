#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> A) {
    int N = A.size();

    // This is done to ensure if we go over bounds.
    // Ex: 9+1 = 10
    vector<int> arr[N+1];
    int carry = 0;
    int add = 0;
    for (int i = N-1; i >=0; i--) {
        carry = (A[i] + 1)/10;
        add = carry + (A[i] + 1)%10;
        arr->push_back(A[i] + add);
    }
    return arr;
}

void print(vector<int> A) {
    for (int i = 0 ; i < A.size(); i++) {
        cout << A[i] << ",";
    }
}

int main() {
    vector<int> A = {1,2,3};
    plusOne(A);
    print(A);
    return 0;
}