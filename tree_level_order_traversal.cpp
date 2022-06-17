/*
 * Challenges: https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
 */
#include <bits/stdc++.h>

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
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
    Node *ans[500];
    int head;
    int tail;

    void levelOrder(Node * root) {
        head = tail = 0;
        ans[tail++] = root;

        while (head < tail) {
            if (ans[head]->left) {
                ans[tail++] = ans[head]->left;
            }
            if (ans[head]->right) {
                ans[tail++] = ans[head]->right;
            }
            ++head;
        }

        for (int i = 0; i < tail; ++i) {
            printf("%d ", ans[i]->data);
        }
    }
}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

	myTree.levelOrder(root);
    return 0;
}

