/*
 * Challenges: https://www.hackerrank.com/challenges/waiter/problem
 */

#include <stdio.h>
#include <memory.h>

char is_prime[10001];
int primes[1300];
int p_num;

int curr[50001];
int next[50001];
int res[50001];

int curr_top;
int next_top;
int res_top;

int main () {
  int n, q;

  memset(is_prime, 0, sizeof(is_prime));
  is_prime[0] = is_prime[1] = 1;
  for (int i = 2; i * i < 10001; ++i) {
    for (int j = i + i; j < 10001; j += i) {
      is_prime[j] = 1;
    }
  }

  int p_num = 0;
  for (int i = 0; i < 10001; ++i) {
    if (is_prime[i] == 0) {
      primes[p_num++] = i;
    }
  }

  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &curr[i]);
  }

  curr_top = n;
  next_top = 0;
  res_top = 0;

  for (int i = 0; i < q; ++i) {
    for (int j = curr_top - 1; j >= 0; --j) {
      if (curr[j] % primes[i] == 0) {
        res[res_top++] = curr[j];
      } else {
        next[next_top++] = curr[j];
      }
    }

    for (int j = res_top - 1; j >= 0; --j) {
      printf("%d\n", res[j]);
    }

    for (int j = 0; j < next_top; ++j) {
      curr[j] = next[j];
    }

    curr_top = next_top;
    next_top = 0;
    res_top = 0;
  }

  for (int i = curr_top - 1; i >= 0; --i) {
    printf("%d\n", curr[i]);
  }

  return 0;
}

