#include <iostream>
#include <vector>

using namespace std;

vector<int> breakingRecords(vector<int> scores) {
    int min = INT_MAX;
    int max = INT_MIN;
    int N = scores.size();
    
    vector<int> res;
    int mincount = -1;
    int maxCount = -1;
    for (int i = 0; i < N; i++) {
        if (scores[i] < min) {
            min = scores[i];
            mincount++;
        }
        if (scores[i] > max) {
            max = scores[i];
            maxCount++;
        }
    }
    res.push_back(maxCount);
    res.push_back(mincount);

    return res;
}

int main() {
    vector<int> scores = {12,24,10,24};
    vector<int> res = breakingRecords(scores);

    cout << res[0] << "," << res[1] ;

    return 0;
}