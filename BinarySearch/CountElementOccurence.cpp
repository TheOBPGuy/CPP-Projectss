#include <iostream>
#include <vector>

using namespace std;

int findCount(vector<int> arr, int B) {
    int count = 0;
    int start = 0;
    int end = arr.size()-1;


    int start1 = -1;
    int end1 = -1;

    // First first
    while (start <= end) {
        int mid = (start+end) / 2;
        // cout << mid << "\n";
        if (arr[mid] < B) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    start1 = start;
    cout << start << "\n";

    // Find end
    end = arr.size()-1;
    while (start <= end) {
        int mid = (start+end) / 2;
        if (arr[mid] > B) {
            end = mid -1;
        } else {
            start = mid +1;
        }
    }
    end1 = end;
    cout << end << "\n";


    return end1-start1+1;
}

int main() {
    
    vector<int> arr = {1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 10};
    cout << findCount(arr,1);
    return 0;
}