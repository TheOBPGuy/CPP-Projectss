#include <iostream>
#include <vector>
#define ll long long
#define mod 10000003

using namespace std;

bool isPossible(vector<int> A, int painters, ll int mid, int time);
int paint(int A, int B, vector<int> C);

bool isPossible(vector<int> A, int painters, ll int mid, int time) {
    long long int tempSum = 0;
    long long int tempPainters = 1;
    ll int cal = 0;
    
    for (int i = 0; i < A.size(); i++) {
        cal = (long long int)A[i]*time; 
        cout << cal << "," << mid << "," << tempPainters << "," << A[i] << "," << time << "\n";
        if (cal > mid) { return false; }

        if ((tempSum + cal) > mid) {
            tempPainters++;
            tempSum = cal;
        } else {
            tempSum = tempSum + cal;
        }
        cout << tempSum << "," << tempPainters << "\n";
    }
    cout << tempPainters << "\n";
    cout << "===========" << "\n";
    if (tempPainters > painters) {
        return false;
    } else {
        return true;
    }
}

int paint(int A, int B, vector<int> C) {
    // 1. Get the highest summation value and the smallest value
    ll int smallest = LONG_MIN; ll int highest = 0;
    for (int i = 0; i < C.size(); i++) {
        // cout << smallest%10000003 << "," << highest << "\n";
        cout << (ll)C[i] << "\n";
        smallest = max(smallest, (ll)C[i]);
        highest += C[i];
    }
    smallest = (smallest*B); highest = (highest*B);

    cout << smallest << "," << highest << "\n";
    long long int mid;
    long long int res = 0;
    while (smallest <= highest) {
        mid = smallest + (highest - smallest)/2;
        if (isPossible(C, A, mid, B)) {
            res = mid%mod;
            highest = mid-1;
        } else {
            smallest = mid+1;
        }
        //cout << smallest << "," << highest << "," << mid << "," << res << "\n";
    }

    if (res == 0) {
        return mid%mod;
    }
    return res%mod;
}

// bool isPossible(int A, int B, vector<int> C,long long int X){
//     int n=C.size();
//    long long int t=X;
//     int i=0,cnt=1;
//     while(i<n){
//         if(cnt>A)
//          return false;
//         if(C[i]>t){
//             cnt++;
//             t=X;
//         }
//         else{
//             t=t-C[i];
//             i++;
//         }
//     }
//     return true;
// }

// int paint(int A, int B, vector<int> C) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//     int n=C.size();
//     long long int sum=0;
//     for(int i=0;i<n;i++)
//      sum=sum%10000003+C[i]%10000003;
//     long long int low=0,high=sum*B;
//     long long int ans=high%10000003;
//     while(low<=high){
//         cout<<low<<" "<<high<<" "<<ans<<endl;
//         long long int mid=low+(high-low)/2;
//         if(isPossible(A,B,C,mid/B)){
//            // cout<<"Hi\n";
//             ans=mid%10000003;
//             high=mid-1;
//         }
//         else low=mid+1;
//     }
//     return ans%10000003;

// }

int main() {
    vector<int> C = {1000000, 1000000}; int A = 1; int B = 1000000;
    cout << paint(A,B,C);
    return 0;
}