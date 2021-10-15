#include <iostream>
#include <vector>
#include <string>

using namespace std;

int flippingMatrix(vector< vector<int> > matrix) {
    int sum = 0;
    int size = matrix.size();
    int steps = matrix.size()/2;

    for (int i = 0 ; i < steps; i++) {
        for (int j = 0; j < steps; j++) {
            sum = sum + max(max(matrix[i][j],matrix[i][size-j-1]), max(matrix[size-i-1][j],matrix[size-i-1][size-j-1]));
        }
    }

    return sum;
}

int main() {
    
    
    return 0;
}