#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int recursive(int num, int power);
int pow(int x, int n, int d);

int recursive(int num, int power) {
    if (power == 1) {
        return num;
    }
    return num*recursive(num, power-1);
}

// 1. Get the power recursively
int powHelper(int x, int n, int d) {
    ll int tempX = (ll int)x;
    ll int tempN = (ll int)n;
    ll int tempD = (ll int)d;

    ll int res = 1;
    ll int temp = x%d;
    while (tempN > 0) {
        //cout << tempX << "," << tempN << "," << res << "First" << "\n" ;
        if (tempN&1) {
            // We are looking at odd numbers
            res = (res*temp)%tempD;
        }
        temp = (temp*temp)%tempD;
        tempN = tempN >> 1;
        //cout << tempX << "," << tempN << "," << res << "\n";
    }
    //cout << res << "," << tempD << "\n";

    if (res<0) {
        //res = (tempD - abs(res)%tempD);
        return tempD - abs(res)%tempD;
    }
    return res%tempD;
}


int main() {
    // 1,2,3,4,5,6,7,8
    int x = -1, n = 2, d=20;

    cout << pow(x,n,d) << "\n";
    cout << pow(x,n,d);
    return 0;
}