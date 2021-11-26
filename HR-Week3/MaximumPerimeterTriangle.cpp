#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    // Create the rest variable here
    // vector<int> result(3);
    int perimeter = INT_MIN;
    vector<int> res;
    int result [3] = {};
    // First convert the vector to an array with [] format
    int arr[sticks.size()];
    for (unsigned int i = 0; i < sticks.size(); i++) {
        arr[i] = sticks[i];
    }

    // Now we want to sort the array
    sort(arr,arr+sticks.size());
    reverse(arr,arr+sticks.size());
    // iternate through the array with counts of 3;
    for (unsigned int i = 0; i < sticks.size()-3; i++) {
        if ((arr[i] + arr[i+1] > arr[i+2]) &&
        (arr[i] + arr[i+2] > arr[i+1]) &&
        (arr[i+2] + arr[i+1] > arr[i])) {
            // check if the other 2 conditions hold true as well
            int tempP = arr[i] + arr[i+1] + arr[i+2];
            if (tempP > perimeter) {
                // cout << tempP << "\n";
                perimeter = tempP;
                // res.push_back(arr[i]);
                // res.push_back(arr[i+1]);
                // res.push_back(arr[i+2]);
                result[0] = arr[i];
                result[1] = arr[i+1];
                result[2] = arr[i+2];
            }
        }
    }


    if (res.size() == 0) {
        res.push_back(-1);
        return res;
    }
    
    int temp;
    temp = res[0];
    res[0] = res[2];
    res[2] = temp;
    // for (int i = 0; i < res.size(); i++) {
    //     res.push_back(result[i]);
    // }



    return res;
    //return result;
}

int main() {
    vector<int> sticks = {1,2,3,4,5,10};
    vector<int> result = maximumPerimeterTriangle(sticks);

    // for (int i = 0; result.size(); i++) {
    //     cout << result[i] << ",";
    // }
    return 0;
}