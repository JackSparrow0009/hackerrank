/*
 * Challenges: https://www.hackerrank.com/challenges/crush/problem
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int left_bound;
  int right_bound;
  long long value;
  long long max;

  struct Node *lc;
  struct Node *rc;
};

struct Tree {
  struct Node *root;

  int construct(int left_bound, int right_bound) {
    int ret = 0;

    root = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == root) {
      ret = 1;
    } else {
      root->left_bound = left_bound;
      root->right_bound = right_bound;
      root->value = 0;
      root->max = 0;
      root->lc = NULL;
      root->rc = NULL;
    }

    return ret;
  }

  int insert(int left_bound, int right_bound, long long value) {
    int ret = 0;
    ret = real_insert(root, left_bound, right_bound, value);
    return ret;
  }

  int real_insert(struct Node *node, int left_bound, int right_bound,
                  long long value) {
    int ret = 0;

    if (left_bound < node->left_bound) {
      left_bound = node->left_bound;
    }
    if (right_bound > node->right_bound) {
      right_bound = node->right_bound;
    }

    if (node->left_bound == left_bound && node->right_bound == right_bound) {
      node->value += value;
      if (node->max + value > node->max) {
        node->max = node->max + value;
      }
    } else {
      int mid = (node->left_bound + node->right_bound) / 2;
      do {
        if (NULL == node->lc) {
          node->lc = (struct Node *)malloc(sizeof(struct Node));
          if (NULL == node->lc) {
            ret = 1;
            break;
          }

          node->lc->left_bound = node->left_bound;
          node->lc->right_bound = mid;
          node->lc->value = 0;
          node->lc->max = 0;
          node->lc->lc = NULL;
          node->lc->rc = NULL;
        }
        if (NULL == node->rc) {
          node->rc = (struct Node *)malloc(sizeof(struct Node));
          if (NULL == node->rc) {
            ret = 1;
            break;
          }

          node->rc->left_bound = mid + 1;
          node->rc->right_bound = node->right_bound;
          node->rc->value = 0;
          node->rc->max = 0;
          node->rc->lc = NULL;
          node->rc->rc = NULL;
        }

        if (node->lc->max + node->value > node->lc->max) {
          node->lc->max = node->lc->max + node->value;
        }
        if (node->rc->max + node->value > node->rc->max) {
          node->rc->max = node->rc->max + node->value;
        }
        node->lc->value += node->value;
        node->rc->value += node->value;
        node->value = 0;

        if (left_bound <= mid) {
          ret = real_insert(node->lc, left_bound, right_bound, value);
          if (0 != ret) {
            break;
          }
        }
        if (right_bound > mid) {
          ret = real_insert(node->rc, left_bound, right_bound, value);
          if (0 != ret) {
            break;
          }
        }

        if (node->lc && node->lc->max > node->max) {
          node->max = node->lc->max;
        }
        if (node->rc && node->rc->max > node->max) {
          node->max = node->rc->max;
        }
      } while (0);
    }
    return ret;
  }
};

int main() {
  int n, m;
  static Tree seg_tree;

  scanf("%d %d", &n, &m);
  seg_tree.construct(1, n);
  for (int i = 0; i < m; ++i) {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    seg_tree.insert(a, b, k);
  }

  printf("%lld\n", seg_tree.root->max);

  return 0;
}

