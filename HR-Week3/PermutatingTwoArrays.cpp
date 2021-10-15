#include <iostream>
#include <vector>

using namespace std;

void quickSort(int arr[], int N);
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end, int pivot);
string twoArrays(int k, vector<int> A, vector<int> B);

void quickSort(int arr[], int N) {
    quickSort(arr, 0, N-1);
}

void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = arr[(start+end)/2];
    int index = partition(arr, start, end, pivot);

    quickSort(arr, start, index-1);
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

            start++;
            end--;
        }
    }
    return start;
}

string twoArrays(int k, vector<int> A, vector<int> B) {
    int arrA[A.size()];
    int arrB[B.size()];

    int size = A.size();
    // Convert both the array
    for (int i = 0; i < A.size(); i++) {
        arrA[i] = A[i];
        arrB[i] = B[i];
    }

    // Sort both the arrays using Quick Sort
    // quickSort(arrA, size);
    // quickSort(arrB, size);

    // sort the arrays 
    sort(arrA,arrA+size);
    sort(arrB,arrB+size);

    int aIndex = 0;
    int bIndex = size-1;
    while (aIndex < size && bIndex >= 0) {
        if (arrA[aIndex] + arrB[bIndex] < k) {
            return "NO";
        }
        aIndex++; bIndex--;
    }


    // for (int i = 0 ; i < size; i++) {
    //     int sum = arrA[i] + arrB[size-i-1];
    //     if (sum < k) {
    //         return "NO";
    //     }
    // }
    return "YES";
}

int main() {
    return 0;
}