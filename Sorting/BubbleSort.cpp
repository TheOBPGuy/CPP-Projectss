#include <iostream>
#include <array>

using namespace std;

// Declare the function calls here
void printArr(int arr[], int size);
void bubbleSort(int arr[]);

/**
 * 5,4,3,2,1
 * 4,3,2,1,5 [1]
 * 3,2,1,4,5 [2]
 * 2,1,3,4,5 [3]
 * 1,2,3,4,5 [4]
 */
void bubbleSort(int arr[], int N) {
    cout << N << "\n";
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Swap the indexes of the elements
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                //cout << temp;
                arr[j] = arr[j+1];
                //cout << arr[j];
                arr[j+1] = temp;
                
            }
        }
    }
}

// Print out the contents of the array
void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr [5] = {5,4,3,2,1};
    int N = (sizeof(arr)/sizeof(*arr));
    // cout << N << "\n";
    bubbleSort(arr,N);
    
    printArr(arr,5);

    return 0;
}