#include <iostream>
#include <vector>

using namespace std;

void quickSort(int arr[], int N);
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end, int pivot);
void print(int arr[]);

void quickSort(int arr[], int N) {
    quickSort(arr, 0, N-1);
}

void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = arr[(start+end)/2];
    int index = partition(arr, start,end,pivot);

    quickSort(arr, start,index-1);
    quickSort(arr, index+1, end);
}

int partition(int arr[], int start, int end, int pivot) {
    while (start <= end) {
        while (arr[start] < pivot) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++; end--;
        }
    }
}

void print(int arr[], int size) {
    // int N = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ",";
    }
}

int solve(vector<int> A, int B) {

    // Initial Checks
    if (B > A.size()) {
        return 0;
    }
    int N = A.size();
    int minCont = INT_MAX;
    // Find the contiguous mininum Sum
    for (int i = 0 ; i < N-(N-B); i++) {
        int tempMin = 0;
        for (int j = 0; j < N-B; j++) {
            tempMin += A[i+j];
        }
        minCont = min(minCont,tempMin);
    }

    cout << minCont << "\n";
    // Get the total sum of the array
    int tot = 0;
    for (int i = 0; i < N; i++) {
        tot += A[i];
    }

    return tot - minCont;
}

int main() {
    // vector<int> A = {5, -2, 3 , 1, 2};
    vector<int> A = {-533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322, -667, 673, -336, 141, 711, -747, -132, 547, 644, -338, -243, -963, -141, -277, 741, 529, -222, -684, 35}; 
    int B = 48;
    cout << solve(A,B);
    return 0;
}