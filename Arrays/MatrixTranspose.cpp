#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > transpose(vector< vector<int> > A) {
    vector< vector<int> > res;
    int N = A.size();
    int M  = A[0].size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            res[j][i] = A[i][j];
        }
    }

    return res;
}

int main() {
    return 0;
}