#include <iostream>
#include <string>
#include <vector>

using namespace std;

void quickSort(int arr[], int N);
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end, int pivot);
int findMedian(vector<int> arr);

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

int findMedian(vector<int> arr) {
    int N = arr.size();
    int temp[N];
    for (int i = 0; i < N; i++) {
        temp[i] = arr[i];
    }

    quickSort(temp, N);
    int  middle = N/2;
    return temp[middle];
}

int main() {
    
    vector<int> arr = {0,1,2,4,6,5,3};
    cout << findMedian(arr);
    return 0;
}