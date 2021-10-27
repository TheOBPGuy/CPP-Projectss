#include <iostream>
#include <vector>

// THIS PROGRAM NEEDS SOME FURTHER WORK

using namespace std;

vector< vector<int> > generateSubArray(vector<int> A) ;
vector<int> solve(vector<int> A, vector<int> B);
void print(vector<int> A);
int getMax(vector<int> A);

void print(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i != A.size()-1) {
            cout << ",";
        }
    }
}

vector< vector<int> > generateSubArray(vector<int> A) {
    vector< vector<int> > sub ;
    // [1,2,3,4]
    for (int i = 0; i < A.size(); i++) { 
        for (int j = i; j < A.size(); j++) {
            vector<int> temp;
            for (int k = i; k <= j; k++) {
                temp.push_back(A[k]);
            }
            sub.push_back(temp);
        }
    }
    return sub;
}

int getMax(vector<int> A) {
    int maxV = INT_MIN;
    for (int i = 0; i < A.size(); i++) {
        maxV = max(maxV, A[i]);
    }
    return maxV;
}

vector<int> solve(vector<int> A, vector<int> B) {
    vector<int> G;
    
    // 1) generate all subarrays of A.
    vector< vector<int> > subArray = generateSubArray(A);

    // 2) take the maximum element from each subarray of A and insert it into a new array G.
    for (int i =0; i < subArray.size(); i++) { 
        int maxV = getMax(subArray[i]);
        G.push_back(maxV);
    }

}

int main() {
    vector<int> A = {1,2,4};
    generateSubArray(A);
    return 0;
}