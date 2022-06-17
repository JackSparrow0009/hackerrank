/*
 * https://www.hackerrank.com/challenges/jesse-and-cookies/problem
 */

#include <stdio.h>

struct Heap {
  int size;
  int data[1000001];
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

  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int value;
    scanf("%d", &value);
    heap.data[++heap.size] = value;
    up(&heap, heap.size);
  }

  int ans = 0;
  while(heap.size > 1 && heap.data[1] < k) {
    int c1 = heap.data[1];
    heap.data[1] = heap.data[heap.size--];
    down(&heap, 1);

    int c2 = heap.data[1];
    heap.data[1] = heap.data[heap.size--];
    down(&heap, 1);

    int c3 = c1 + 2 * c2;
    heap.data[++heap.size] = c3;
    up(&heap, heap.size);

    ++ans;
  }

  printf("%d\n", (heap.data[1] < k) ? -1 : ans);

  return 0;
}

