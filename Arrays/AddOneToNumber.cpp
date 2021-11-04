#include <iostream>
#include <vector>

using namespace std;
void printArr(int B[], int size);
vector<int> convertArrToVec(int A[], int size, bool takeFirst, bool firstZero);
void print(vector<int> A);

vector<int> plusOne(vector<int> A) {
    int N = A.size();

    // This is done to ensure if we go over bounds.
    // Ex: 9+1 = 10
    bool firstIsZero = false;
    if (A[0] == 0 and A.size() != 1) {
        firstIsZero = true;
    }

    vector<int> arr;
    int B[N+1];
    // Fill this array randomly at first
    for (int i = 0; i < N+1; i++) {
        B[i] = INT_MAX;
    }

    int carry = 0;
    // int carry = (A[N-1] + 1)/10;
    int add = 0;
    bool first = true;
    for (int i = N-1; i >= 0; i--) {
        if (first) {
            // Only Add one if First
            add = (A[i] + 1)%10;
            carry = (A[i] + 1)/10;
            first = false;
        }
        else {
            add = (carry + A[i])%10;
            carry = (carry + A[i])/10;
        }
        arr.push_back(add);
        B[i+1] = add;
        printArr(B,N+1);
        cout << "\n";
    }
    // Fill in the first column only if there is a carry value
    vector<int> res;

    if (carry != 0) {
        B[0] = carry;
        arr.push_back(carry);
        res = convertArrToVec(B,N+1,true, firstIsZero);
    } else {
        res = convertArrToVec(B,N+1,false, firstIsZero);
    }

    //cout << "Finally" << "\n";
    //printArr(B,N+1);
    // Conver the arr to a vector now:
    
    //cout << "\n" << "Result" << "\n";
    //print(res);

    //cout << "\n";
    return res;
}

vector<int> convertArrToVec(int A[], int size, bool takeFirst, bool firstZero) {
    vector<int> arr;
    int start = 0;
    if (!takeFirst) {
        start = 1;
    }
    if (firstZero) {
        int idx = 0;
        while (true) {
            if (A[idx+1] == 0) {
                start++;
            } else {
                break;
            }
            idx++;
        }
        
    }

    for (int i = start; i < size; i++) {
        arr.push_back(A[i]);
    }
    return arr;
}


void printArr(int B[], int size) {
    for (int i =0; i < size; i++) {
        cout << B[i] << ",";
    }
}

void print(vector<int> A) {
    for (int i = 0 ; i < A.size(); i++) {
        cout << A[i] << ",";
    }
}

int main() {
    vector<int> A = {0, 3, 7, 6, 4, 0, 5, 5, 5};
    vector<int> arr = plusOne(A);
    print(A);
    cout << "\n";
    print(arr);
    return 0;
}