#include <iostream>
#include <vector>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

using namespace std;

long long int getNum(int range, int num);

long long solve (int range) {
    long long int three = getNum(range, 3);
    long long int five = getNum(range, 5);
    return three + five;
}

long long int getNum(int range, int num) {
    long long int res = 0;
    for (int i = num; i < range; i++) {
        if (i % num == 0) {
            res += i;
        }
    }
    return res;
}

int main() {
    int range = 1000;
    cout << solve(range);
    return 0;
}