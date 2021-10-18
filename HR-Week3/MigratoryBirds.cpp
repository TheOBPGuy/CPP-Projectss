#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int migratoryBirds(vector<int> arr) {

    unordered_map<int, int> map ;
    for (int i = 0; i < arr.size(); i++) {
        auto temp = map.find(arr[i]);
        if (temp != map.end()) {
            temp->second++;
        } else {
            map.insert({arr[i],1});
        }
    }

    int minKey = INT_MAX;
    int maxVal = INT_MIN;

    // Iterate through the map once and get the 
    // highest value Value from the map
    for (const auto &pair : map) {
        if (pair.second >= maxVal) {
            maxVal = pair.second;
            minKey = pair.first;
        }
    }

    // Iterate through the map a second time
    // This time try to pull out any other values which are lower
    // than the original Key
    for (const auto &pair : map) {
        if (pair.second >= maxVal) {
            // we are looking at only the Duplciates at this time
            if (pair.first <= minKey) {
                minKey = pair.first;
            }
        }
    }

    return minKey;

    // // Copy vector into array
    // int array[arr.size()];
    // for (unsigned int i = 0; i < arr.size(); i++) {
    //     array[i] = arr[i];
    // }

    // // Sort the array at first
    // sort(array, array+arr.size());
    // int maxV = INT_MIN;
    // int minV = INT_MAX;
    // int count = 0;
    // unordered_map<int, int> map;
    // for (unsigned int i = 0; i < arr.size(); i++) {
    //     auto temp = map.find(array[i]);
    //     if (temp != map.end()) {
            
    //     } else {
    //         map.insert({array[i],-1});
    //         maxV = max(maxV,count);
    //         minV = min(minV,arr);
    //         count = 0;
            
    //     }
    //     count++;
    // }
    // return maxV;
}

int main() {
    vector<int> arr = {1,1,2,2,3};
    cout << migratoryBirds(arr);
    return 0;
}