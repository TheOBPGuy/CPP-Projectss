#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int diagonalDfference(vector< vector<int> > arr) {
    int d1 = 0;
    int d2 = 0;
    int rightD = arr.size()-1;
    for (unsigned int i = 0; i < arr.size(); i++) {
        d1 += arr[i][i];
        d2 += arr[i][rightD];
        rightD--;
    }

    int sum = abs(d1-d2);
    return sum;

}

int main() {
    
    return 0;
}