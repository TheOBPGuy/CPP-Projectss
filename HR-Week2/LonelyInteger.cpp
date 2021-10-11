#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lonelyinteger(vector<int> a) {
    unordered_map<int, int> map;
    for (int i = 0; i < a.size(); i++) {
        // check if map contains or not.
        // If not then we will enter the element into the map
        auto temp = map.find(a[i]);
        if  (temp != map.end()) {
            temp->second++;
            // map.find(temp)->second++;
            
        } else {
            map.insert({a[i],1});
        }
    }

    for (const pair<int, int>& val : map) {
        // cout << val.first << "," << val.second << "\n";
        if (val.second == 1) {
            return val.first;
        }
    }
    return 0;
}

int main() {

    vector<int> arr = {1,2,3,4,3,2,1};
    cout << lonelyinteger(arr);
    return 0;
}