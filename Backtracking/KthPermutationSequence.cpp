#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> A);

/**
 * @brief 
 * The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,

We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"
 * 
 * @param n 
 * @param k 
 * @return string 
 */
string solve(int n, int k) {
    vector<int> numbers;
    vector<int> factorials;
    int fact = 1;
    for (int i = 1; i < n; i++) {
        numbers.push_back(i);
        fact = fact * i;
        factorials.push_back(fact);
    }

    // Decrement k by 1 since we are starting at the 0th index
    k = k - 1;
    numbers.push_back(n);
    printVector(numbers);
    cout << "\n";
    printVector(factorials);

    string ans = "";

    while (true) {
        // Keep iterating until the factorials have been fully exhausted
        int index = k / fact;
        int first_elem = numbers[index];
        ans += to_string(first_elem);
        factorials.remove(index);

        if (factorials.size() == 0) {
            // break out of while loop
            break;
        }

        // Otherwise keep updating the k and fact values
        k = k % fact;
        fact = fact / factorials.size();
    }

    return ans;
}

void printVector(vector<int> A) {
    for (int i = 0 ; i < A.size(); i++) {
        cout << A[i] << ",";
    }
}

int main() {
    solve(4,17);
    return 0;
}   