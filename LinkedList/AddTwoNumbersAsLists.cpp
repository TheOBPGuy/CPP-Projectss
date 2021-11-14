#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* solve(int A, int B) {
    int sum = A + B;
    string sumNum = to_string(sum);

    ListNode* head = new ListNode(1);
    ListNode* current = head;

    for (int i = 1; i < sumNum.size(); i++) {
        if (i == 0 && sumNum[i] == 0) {
            continue;
        }

        char c = sumNum[i];
        string s(1, c);
        int numTemp = stoi(s);
        ListNode* temp = new ListNode(numTemp);
        current->next = temp;
        current = temp;
    }


    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    // cout << "Hello";
    while(current->next != NULL) {
        cout << current->val << "->";
        current = current->next;
    }

    if (current != nullptr) {
        cout << current->val;
    }
}

int main() {
    int A = 7;
    int B = 5;

    ListNode* res = solve(A, B);
    printList(res);

    return 0;
}