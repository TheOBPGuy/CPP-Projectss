#include <iostream>
#include <vector>

using namespace std;

int coverPoints(vector<int> A, vector<int> B) {
     int steps = 0;
     int size = A.size();

    if (size <= 1) { 
        return 0;
    }

    int currentX = A[0];
    int currentY = B[0];

     for (int i = 1; i < size; i++) {
        int diffX = abs(currentX - A[i]);
        int diffY = abs(currentY - B[i]);
        cout << diffX << "," << diffY << "," << steps << "," << "First" << "\n";
        while (diffX != 0 and diffY != 0) {
            diffX--; diffY--;
            steps++;
        }
        if (diffY == 0) {
            while (diffX != 0) {
                diffX--;
                steps++;
            }
        }
        if (diffX == 0) {
            while (diffY != 0) {
                diffY--;
                steps++;
            }
        }
        currentX = A[i];
        currentY = B[i];
        cout << diffX << "," << diffY << "," << steps << "," << "Second" << "\n";
     }
    
    return steps;
}

int main() {
    vector<int> A = {0,1,1};
    vector<int> B = {0,1,2};
    cout << coverPoints(A,B);
    return 0;
}