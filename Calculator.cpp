#include <iostream>

using namespace std;

class Calculator {

    public:
        int getSum(int a, int b) {
            return a+b;
        }

        int getDiff(int a, int b) {
            return a-b;
        }

        int getMulti(int a, int b) {
            return a*b;
        }

        int getDiv(int a, int b) {
            return a/b;
        }
};

int main() {
    Calculator myCalc;
    cout << myCalc.getSum(2,2) << "\n";
    cout << myCalc.getDiff(2,2)<< "\n";
    cout << myCalc.getMulti(2,2)<< "\n";
    cout << myCalc.getDiv(2,2)<< "\n";

    return 0;
}