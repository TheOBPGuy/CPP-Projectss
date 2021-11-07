#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool ijIsLarger(string ij, string ji);

string largestNumber(vector<int> A) {
    string res = "";
    const int N = A.size();
    
    // Place the vector into an array. So it will be easier to 
    // to move elements:
    int arr[A.size()];
    for (int i = 0; i < N; i++) {
        arr[i] = A[i];
    }

    for (int i = 0; i < N; i++) {
        string ij = "";
        string ji = "";
        for (int j = i+1; j < N; j++) {
            ij = to_string(arr[i]) + to_string(arr[j]);
            ji = to_string(arr[j]) + to_string(arr[i]);
            
            cout << ij << "," << ji << "\n"; 
            if (!ijIsLarger(ij, ji)) {
                cout << "Hello" << "\n";
                // Only if the JI value is larger will be switch the i'th place
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Create the array finally
    for (int i = 0; i < N; i++) {
        res += to_string(arr[i]);
    }

    if (arr[0] == 0) {
        return "0";
    }

    return res;
}

bool ijIsLarger(string ij, string ji) {
    long long int ijNum = stoll(ij);
    long long int jiNum = stoll(ji);
    return ijNum >= jiNum ? true : false;
}

int main() {
    vector<int> A = {3, 30, 34, 5, 9 };
    cout << largestNumber(A);
    return 0;
}