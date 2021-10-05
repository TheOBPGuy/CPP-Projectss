#include <iostream>
#include <vector>

using namespace std;

void quickSort(int arr[]);
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end, int pivot);
void swap(int arr[], int start, int end);
void miniMaxSum(vector<int> arr);

void miniMaxSum(vector<int> arr) {
    
    // First convert the array 

    int min = INT_MAX;
    int max = INT_MIN;
    
    long minSum = 0;
    long maxSum = 0;

    int N = arr.size();

    for (int i = 0; i < N; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        
        minSum = minSum + arr[i];
        maxSum = maxSum + arr[i];
    }

    cout << min << "\n";
    cout << max << "\n";

    minSum = minSum - max;
    maxSum = maxSum - min;

    cout << minSum << " " << maxSum;
    // cout << max << "\n";
}

void quickSort(int arr[], int N) {
    
    quickSort(arr, 0, N-1);
}

void quickSort(int arr[], int start, int end) {
    if (start >= end) {
        // Recursion Base Case
        return;
    }
    int pivot = arr[(start+end)/2];
    int index = partition(arr,start, end, pivot);

    // cout << pivot << "," << index << "\n";

    quickSort(arr,start,index-1);
    quickSort(arr,index, end); 
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
            // swap(arr,start,end);

            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }
    return start;
}

void swap(vector<int> arr, int start, int end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

int main() {
    vector<int> arr1 = { 256741038, 623958417, 467905213, 714532089, 938071625};
    int arr[] = { 5,4,3,2,1 };

    // Sort the array in ascending order:
    // quickSort(arr, 5);

    // for (int val : arr) {
    //     cout << val;
    // }

    miniMaxSum(arr1);

    return 0;
}