#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int> A, int B) {
    vector<int> tempRange ;
    // int tempRange[A.size()];
    // int tempSize = sizeof(tempRange)/sizeof(tempRange[0]);
    int N = A.size();
    int lo = 0; int hi = N -1; int mid;

    int start, end = -1;
    int idx=0;

    // First get the start
    bool found1 = false;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        if (A[mid] < B) {
            lo = mid+1;
        } else if (A[mid] > B) {
            hi = mid-1;
        } else {
            found1 = true;
            tempRange.push_back(mid);
            // tempRange[idx++] = mid;
            // cout << mid << "\n";
            hi = mid-1;
        }
    }
    
    if (!found1) {
        start = -1;
    } else {
        start = tempRange[tempRange.size()-1];
        cout << start;
    }
    // start = tempRange[tempSize-1];
    

    // Second get the END index;
    int lo2 = 0; int hi2 = N -1; int mid2;
    bool found2 = false;
    vector<int> tempRange2;
    while (lo2 <= hi2) {
        mid2 = lo2 + (hi2-lo2)/2;
        if (A[mid2] < B) {
            lo2 = mid2+1;
        } else if (A[mid2] > B) {
            hi2 = mid2-1;
        } else {
            found2 = true;
            tempRange2.push_back(mid2);
            lo2 = mid2+1;
        }
    }
    
    if (!found2) {
        end = -1;
    } else {
        end = tempRange2[tempRange2.size()-1];
        cout << end;
    }
    

    vector<int> res;
    if ((tempRange.size() == 0 || tempRange.empty()) and (tempRange2.size() == 0 || tempRange2.empty())) {
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }

    // res.push_back(tempRange[tempRange.size()-1]);
    // res.push_back(tempRange2[tempRange2.size()-1]);
    res.push_back(start); res.push_back(end);

    cout << "\n";
    cout << res[0] << "," << res[1] ;

    return res;
}

int main() {
    vector<int> A = {4, 7, 7, 7, 8, 10, 10};
    int B = 3;
    searchRange(A,B);
    return 0;
}