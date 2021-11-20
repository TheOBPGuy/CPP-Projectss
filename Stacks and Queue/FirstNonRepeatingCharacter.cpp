#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * @brief Given a string A denoting a stream of lowercase alphabets. You have to make new string B.
 * B is formed such that we have to find first non-repeating character each time a character is inserted 
 * to the stream and append it at the end to B. 
 * If no non-repeating character is found then append '#' at the end of B
 * 
 * @param A 
 * @return string 
 */
string solve(string A) {
    queue<char> q;
    unordered_map<char, int> map;
    string res = "";

    for (int i = 0; i < A.size(); i++) {
        // Step 1:
        // First check if its already present in the map
        // If not then add to map. If its already present 
        // them simply append the occurence value
        if (map.find(A[i]) == map.end()) {
            // Not found
            map[A[i]] = 1;
        } else {
            // Found
            map[A[i]]++;
        }
        cout << A[i] << "--->" << map[A[i]] << "\n";
        bool isEmpty = false;
        char topElement;
        // Step 2:
        if (map[A[i]] > 1) {
            // Remove the top of queue. Dequeue
            if (!q.empty()) {
                //topElement = q.front();
                q.pop();
                
            } else {
                isEmpty = true;
            }
        } else {
            // Enqeue element
            q.push(A[i]);
            ///topElement = q.front();
        }

        // Step 3:
        topElement = q.front();
        if (isEmpty) {
            res += "#";
        } else {
            if (q.empty()) {
                res += "#";
            } else {
                string s(1,topElement);
                res += s;    
            }
            // string s(1,topElement);
            // res += s;
        }

    }

    return res;
}

int main() {
    string A = "abadbc";
    cout << solve(A);
    return 0;
}