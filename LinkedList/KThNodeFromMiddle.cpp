#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getMiddleIndex(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    int idx = 0;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        idx++;
    }
    return idx;
}

int solve(ListNode* A, int B) {
    if (A == nullptr) {
        return -1;
    }

    ListNode* temp = A;
    // Find the index for the middle element
    int middle_index = getMiddleIndex(A);
    int count = middle_index - B;
    if (count < 0) { return -1; }

    else {
        while (count != 0) {
            A = A->next;
            count--;
        }    
        cout << A->val << "\n";
    }
    
    return A->val;
}

int main() {
    ListNode* A = new ListNode(3);
    A->next = new ListNode(4);
    A->next->next = new ListNode(7);
    A->next->next->next = new ListNode(5);
    A->next->next->next->next = new ListNode(6);
    A->next->next->next->next->next = new ListNode(16);
    A->next->next->next->next->next->next = new ListNode(15);
    A->next->next->next->next->next->next->next = new ListNode(61);
    A->next->next->next->next->next->next->next->next = new ListNode(16);

    int B = 3;
    int res = solve(A, B);
    cout << res;

    return 0;
}