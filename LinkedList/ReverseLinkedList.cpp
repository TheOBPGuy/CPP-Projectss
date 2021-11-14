#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

ListNode* reverse(ListNode* A) {
    if (A == nullptr) {
        return A;
    }
    ListNode* prev = nullptr;
    ListNode* current = A;
    ListNode* next = A;

    while (current != nullptr) { 
        next = next->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);

    printList(list);
    ListNode* reversed = reverse(list);
    cout << "\n";
    printList(reversed);
    return 0;
}