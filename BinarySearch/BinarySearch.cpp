#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n-1;

    while (start <= end) {
        int middle = (start+end) / 2;

        if (arr[middle] == target) {
            // First check if the target has been found or not
            return middle;
        }
        if (arr[middle] > target) {
            end = middle - 1;
        } else {
            start = middle+1;
        }
    }

    return -1;
}

int main() {
    return 0;
}