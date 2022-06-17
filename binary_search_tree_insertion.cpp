/*
 * Challenges: https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem
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

  	void preOrder(Node *root) {

      	if( root == NULL )
          	return;

      	std::cout << root->data << " ";

      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as

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

*/

    Node * insert(Node * root, int data) {
        if (NULL == root) {
            root = new Node(data);
        } else {
            Node *iter = root;
            while (true) {
                if (iter->data >= data) {
                    if (iter->left) {
                        iter = iter->left;
                    } else {
                        iter->left = new Node(data);
                        break;
                    }
                } else {
                    if (iter->right) {
                        iter = iter->right;
                    } else {
                        iter->right = new Node(data);
                        break;
                    }
                }
            }
        }

        return root;
    }

};

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

    myTree.preOrder(root);

    return 0;
}

