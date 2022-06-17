/*
 * Challenges: https://www.hackerrank.com/challenges/tree-top-view/problem
 */

#include<bits/stdc++.h>

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

/*
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
    int ans[1200];
    int depth[1200];
    int mid;

    void dfs(Node *root, int i, int d) {
        if (NULL == root) {
            return;
        }
        if (depth[i] > d) {
            ans[i] = root->data;
            depth[i] = d;
        }
        dfs(root->left, i - 1, d + 1);
        dfs(root->right, i + 1, d + 1);
    }

    void topView(Node * root) {
        mid = 600;
        for (int i = 0; i < 1200; ++i) {
            depth[i] = 99999;
        }
        dfs(root, mid, 0);

        for (int i = 0; i < 1200; ++i) {
            if (depth[i] < 99999) {
                printf("%d ", ans[i]);
            }
        }
        return;
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

	myTree.topView(root);
    return 0;
}

