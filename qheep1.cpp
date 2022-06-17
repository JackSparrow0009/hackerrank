/*
 * Challenges: https://www.hackerrank.com/challenges/qheap1/problem
 */
#include <stdio.h>

struct Heap {
  int size;
  int data[100001];
};

void up(struct Heap *heap, int index) {
  if (index < 1 || index > heap->size) {
    return;
  }

  int curr = index;
  int value = heap->data[curr];
  int father = curr / 2;

  while (father) {
    if (heap->data[father] > value) {
      heap->data[curr] = heap->data[father];
      curr = father;
      father = curr / 2;
    } else {
      break;
    }
  }
  heap->data[curr] = value;

  return;
}

void down(struct Heap *heap, int index) {
  if (index < 1 || index > heap->size) {
    return;
  }

  int curr = index;
  int value = heap->data[curr];
  int son = curr * 2;

  while (son <= heap->size) {
    if (son < heap->size && heap->data[son] > heap->data[son + 1]) {
      ++son;
    }

    if (heap->data[son] < value) {
      heap->data[curr] = heap->data[son];
      curr = son;
      son = curr * 2;
    } else {
      break;
    }
  }
  heap->data[curr] = value;

  return;
}

int main () {
  static struct Heap heap;
  heap.size = 0;
  static struct Heap del;
  del.size = 0;

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int cmd = 0;
    scanf("%d", &cmd);
    if (1 == cmd) {
      int value = 0;
      scanf("%d", &value);
      heap.data[++heap.size] = value;
      up(&heap, heap.size);
    } else if (2 == cmd) {
      int value = 0;
      scanf("%d", &value);
      del.data[++del.size] = value;
      up(&del, del.size);

      while (heap.size > 0 && del.size > 0 && heap.data[1] == del.data[1]) {
        heap.data[1] = heap.data[heap.size--];
        down(&heap, 1);
        del.data[1] = del.data[del.size--];
        down(&del, 1);
      }
    } else if (3 == cmd) {
      printf ("%d\n", heap.data[1]);
    }
  }
  return 0;
}

