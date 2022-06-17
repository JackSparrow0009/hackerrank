/*
 * Challenges: https://www.hackerrank.com/challenges/counting-road-networks/problem
 */

#include <stdio.h>

typedef long long int64;

#define MAX_N  (150000)
#define MODULE (663224321)

static int64 f[MAX_N];
static int64 g[MAX_N];
static int64 factorial_inverse[MAX_N]; // (x! * inverse[x]) % module == 1
static int64 factorial[MAX_N];         // factorial[x] == x!
static int64 x1[MAX_N];
static int64 x2[MAX_N];
static int64 y[MAX_N];

int64 power(int64 x, int64 n) { // (x ** n) % module
  int64 res = 1;
  for (; n; n >>= 1, x = x * x % MODULE) {
    if (n & 1) {
      res = (res * x) % MODULE;
    }
  }

  return res;
}

void FFT(int64 *x, int64 n, int64 rev) {
  for (int64 i = 1, j, k, t; i < n; ++i) {
    for (j = 0, t = i, k = n >> 1; k; t >>= 1, k >>= 1) {
      j = j << 1 | t & 1;
    }
    if (i < j) {
      int64 tmp = x[i];
      x[i] = x[j];
      x[j] = tmp;
    }
  }

  for (int64 s = 2, ds = 1; s <= n; ds = s, s <<= 1) {
    int64 wn = power(3, (MODULE - 1) / s) ;
    if (rev < 0) {
      wn = power(wn, MODULE - 2);
    }
    for (int64 k = 0; k < n; k += s) {
      int64 w = 1, t;
      for (int64 i = k; i < k + ds; ++ i, w = w * wn % MODULE) {
        x[i + ds] = (x[i] - (t = w * x[i + ds] % MODULE) + MODULE) % MODULE;
        x[i] = (x[i] + t) % MODULE;
      }
    }
  }
  if (rev < 0) {
    int64 invn = power(n, MODULE - 2) ;
    for (int64 i = 0; i < n; ++ i) {
      x[i] = x[i] * invn % MODULE;
    }
  }
}

void divide_conquer(int64 left, int64 right) {
  if (left == right) {
    return;
  }
  int64 mid = (left + right) / 2;
  divide_conquer(left, mid);

  int64 n1;
  for (n1 = 1; n1 <= right - left; n1 <<= 1);

  for (int64 i = 0; i < n1; ++i) {
    x1[i] = (i + left <= mid) ? f[i + left] * factorial_inverse[i + left - 1] % MODULE : 0;
    x2[i] = (i + left <= right) ? factorial_inverse[i + 1] * g[i + 1] % MODULE : 0;
  }
  FFT(x1, n1, 1);
  FFT(x2, n1, 1);

  for (int64 i = 0; i < n1; ++i) {
    y[i] = x1[i] * x2[i] % MODULE;
  }

  FFT(y, n1, -1);
  for (int64 i = mid + 1; i <= right; ++i) {
    f[i] = (f[i] - (factorial[i - 1] * y[i - left - 1] % MODULE) + MODULE) % MODULE;
  }

  divide_conquer(mid + 1, right);
}

void initialize() {
  factorial[0] = 1;
  factorial_inverse[0] = 1;

  for (int64 i = 1; i < MAX_N; ++i) {
    factorial[i] = (factorial[i - 1] * i) % MODULE;
    factorial_inverse[i] = power(factorial[i], MODULE - 2);

    g[i] = power(2, (int64)i * (int64)(i - 1) / 2);
    f[i] = g[i];
  }

  divide_conquer(1, 100000);
}

int main () {
  int q, n;

  initialize();

  scanf("%d", &q);
  for (int64 i = 0; i < q; ++i) {
    scanf("%d", &n);
    printf("%lld\n", f[n]);
  }

  return 0;
}


