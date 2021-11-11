#include <iostream>
#include <math.h>

using namespace std;


bool checkifSquare(int num);

int solve(int A, int B) {
    int res = 0;
    for (int i = A; i <= B; i++) {
        if (checkifSquare(i)) {
            res++;
        }
    }
    return res;
}

bool checkifSquare(int num) {
    if (num <= 0) {    
        return false;
    } else {
        long long int square = sqrt(num);
        if (square * square == num) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    int A = 50000;
    int B = 60000;
    cout << solve(A,B);
    return 0;
}