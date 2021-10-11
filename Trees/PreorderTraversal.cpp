
#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }

    int main() {
        return 0;
    }   
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if (root == NULL) {
                return new Node(data);
            } else {
                if (data <= root->data) {
                    root->left = insert(root->left, data);
                } else {
                    root->right = insert(root->right,data);
                }
            }
            return root;
        }

        void preOrder(Node* root) {
            if (root == NULL) {
                return;
            }
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }

        void postOrder(Node* root) {
            if (root == NULL) {
                return;
            }
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }

        void inOrder(Node* root) {
            if (root == NULL) {
                return;
            }
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
         }
}
