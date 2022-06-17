/*
 * Challenges: https://www.hackerrank.com/challenges/self-balancing-tree/problem
 */

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */


inline int get_height(node *root) {
  return (NULL != root) ? (root->ht) : (-1);
}

inline int set_height(node *root) {
  return (NULL != root) ? (std::max(get_height(root->left), get_height(root->right)) + 1) : (-1);
}

inline int get_balance_factor(node *root) {
  return (NULL != root) ? (get_height(root->left) - get_height(root->right)) : (0);
}

node *right_rotate(node *root) {
  node *new_root = root->left;
  root->left = root->left->right;
  new_root->right = root;

  root->ht = set_height(root);
  new_root->ht = set_height(new_root);

  return new_root;
}

node *left_rotate(node *root) {
  node *new_root = root->right;
  root->right = root->right->left;
  new_root->left = root;

  root->ht = set_height(root);
  new_root->ht = set_height(new_root);

  return new_root;
}

node *insert(node *root, int val) {
  if (NULL == root) {
    root = (node *) malloc(sizeof(node));

    root->val = val;
    root->left = NULL;
    root->right = NULL;
  } else {
    if (val < root->val) {
      root->left = insert(root->left, val);
    } else if (root->val < val) {
      root->right = insert(root->right, val);
    }

    int balance_factor = get_height(root->left) - get_height(root->right);
    if (balance_factor > 1) {
      if (get_height(root->left->left) >= get_height(root->left->right)) {
        root = right_rotate(root);
      } else {
        root->left = left_rotate(root->left);
        root = right_rotate(root);
      }
    } else if (balance_factor < -1) {
      if (get_height(root->right->right) >= get_height(root->right->left)) {
        root = left_rotate(root);
      } else {
        root->right = right_rotate(root->right);
        root = left_rotate(root);
      }
    }
  }
  root->ht = set_height(root);

  return root;
}

