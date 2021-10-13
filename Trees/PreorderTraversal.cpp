#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <map>

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

         int height(Node* root) {
             if (root == NULL) {
                 return 0;
             }
             int left = height(root->left);
             int right = height(root->right);
             return 1 + max(left, right);
         }

         int heightBFS(Node* root) {
             return bfs(root);
         }

        bool contains(vector<int> arr, int target) {
            bool res = false;
            if (find(arr.begin(), arr.end(), target) != arr.end()) {
                res = true;
            }
            return res;
        }

         int bfs(Node* root) {
            if (root == NULL) {
                return 0;
            }

            int depth = 0;
            queue<Node*> queue;
            queue.push(root);
            
            while (!queue.empty()) {
                int size = queue.size();
                for (int i = 0; i < size; i++) {
                    Node* currentNode = queue.front();
                    queue.pop();
                    if (currentNode->left != NULL) {
                        queue.push(currentNode->left);
                    }
                    if (currentNode->right != NULL) {
                        queue.push(currentNode->right);
                    }
                }
                depth++;
            }
            return depth;
         }

        static vector<int> levelOrderTraversal(Node* root) {
            if (root == NULL) {
                vector<int> temp;
                return temp;
            }
            vector<int> arr;
            queue<Node*> queue;
            queue.push(root);
            arr.push_back(root->data);
            while(!queue.empty()) {
                int size = queue.size();
                for (int i = 0; i < size; i++) {
                    Node* currentNode = queue.front();
                    queue.pop();
                    if (currentNode->left != NULL) {
                        queue.push(currentNode->left);
                    }
                    if (currentNode->right != NULL) {
                        queue.push(currentNode->right);
                    }
                    arr.push_back(currentNode->data);
                }
            }
            return arr;
        }

        static int findHD(map<int, vector<Node*> > map, Node* target) {
            int res = 0;
            for (auto it=map.begin(); it != map.end(); ++it) {
                vector<Node*> arr = it->second;
                for (int i = 0 ; i < arr.size(); i++) {
                    if (arr[i] == target) {
                        return it->first;
                    }
                }
            }
            return -1;
        }

        static map<int, vector<Node> > verticalOrderTraversal(Node* root) {
            if (root == NULL) {
                map<int, vector<Node> > temp;
                return temp;
            }

            map<int, vector<Node> > map;
            // vector<Node*> start;
            // start.push_back(root);
            map[0] = vector<Node>();
            Node* firstNode = root;
            map[0].push_back(*firstNode);
            // map.insert(make_pair<int, vector<Node> >(0, start));

            queue<Node*> queue;
            queue.push(root);
            while(!queue.empty()) {
                int size = queue.size();
                for (int i = 0; i < size; i++) {
                    Node* currentNode = queue.front();
                    queue.pop();
                    // int hdParent = findHD(map, currentNode);
                    int hdParent = 0;
                    for (auto it=map.begin(); it != map.end(); ++it) {
                        // vector<Node*> arr = it->second;
                        for (int i = 0 ; i < it->second.size(); i++) {
                            if (it->second[i] == currentNode->data) {
                                hdParent = it->first;
                            }       
                        }
                    }
                    if (currentNode->left != NULL) {
                        // Check if the value is already in the map
                        int leftVal = hdParent -1;
                        auto leftTemp = map.find(leftVal);
                        if (leftTemp != map.end()) {
                            vector<Node*> leftVec = leftTemp->second;
                            leftVec.push_back(currentNode->left);
                            
                            // check if the value is present inside the map as a key.
                            // if so then extract the vector and just add the node to that vector array

                            // otherwise create a new key and value pair
                        } else {
                            vector<Node*> tempLeft;
                            tempLeft.push_back(currentNode->left);
                            map.insert(pair<int, vector<Node*> >(leftVal, tempLeft));
                        }
                    }
                }
                
            }
            return map;
        }
        
};

int main() {
    Node* root = new Node(1);
    root->left  = new Node(2);
    // root->right = new Node(2);
    // root->right->right = new Node(5);
    // root->right->right->left = new Node(3);
    // root->right->right->right = new Node(6);
    // root->right->right->left->right = new Node(4);

    // vector<int> arr = Solution::levelOrderTraversal(root);
    map<int, vector<Node> > map = Solution::verticalOrderTraversal(root);
    for (auto it=map.begin(); it != map.end(); ++it) {
        vector<Node*> arr = it->second;
        cout << it->first << "\n";
        for (int i = 0 ; i < arr.size(); i++) {
            cout << arr[i]->data;
        }
    }

    return 0;
}