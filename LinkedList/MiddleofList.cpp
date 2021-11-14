#include <iostream>

using namespace std;

// ListNode* middleNode(ListNode* head);
// void printList(ListNode* head);
// ListNode* mergeList(ListNode* left, ListNode* right);

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != NULL and fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(ListNode* head) {
    ListNode* current = head;
    // cout << "Hello";
    while(current != NULL) {
        cout << current->val << ",";
        current = current->next;
    }
}

ListNode* mergeList(ListNode* left, ListNode* right) {
    // Check if the lists are null or not
    if (left == nullptr) { return right; }
    if (right == nullptr) { return left; }

    ListNode* head = left;
    if (left->val < right->val) {
        head = left;
        left = left->next;
    } else {
        head = right;
        right = right->next;
    }

    ListNode* current = head;
    // head = current;
    while (left != nullptr && right != nullptr) {
        ListNode* temp = nullptr;
        if (left->val <= right->val) {
            temp = left;
            // current = left;
            left = left->next;
        } else {
            temp = right;
            // current = right;
            right = right->next;
        }
        current->next = temp;
        current = temp;
    }
    // Fill in the remaining blank spaces with whichever
    // List has not yet been filled
    if (left != nullptr) {
        //cout << "hello1";
        current->next = left;
    } else if (right != nullptr) {
        //cout << "hello2";
        current->next = right;
    }
    // printList(current);
    // printList(head);

    // delete current;
    return head;

}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    printList(l1);
    cout << "\n";
    printList(l2);
    cout << "\n";
    ListNode* result = mergeList(l1,l2);
    printList(result);

    return 0;
}