#include <iostream>
#include <vector>

using namespace std;

int countingValleys(int steps, string path) {
    vector<int> arr(steps+1);
    arr[0] = 0;
    int current = 0;
    for (int i =0; i < path.size(); i++) {
        if (path[i] == 'U') {
            current++;
        } else {
            current--;
        }
        arr[i+1] = current;
    }

    // for (int i =0; i < arr.size(); i++) {
    //     cout << arr[i] << ",";
    // }

    int val = 0;
    bool found = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            if (found) {
                val++;
            }
            found = true;
        }
        if (found) {
            if (arr[i] > 0) {
                // We are going UP.
                // So not a valid Valley
                found = false;
            } else {
                continue;
            }
        }
    }
    return val;
}

int main() {
    int steps;
    string path;
    cin >> steps;
    cin >> path;

    cout << "\n";
    cout << countingValleys(steps,path);
    return 0;
}