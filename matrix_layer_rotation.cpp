/*
 * Challenges: https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
 */
#include <stdio.h>

int mat[300][300];

void rotate_step(int n_rows, int n_cols, int begin_row, int begin_col, int *finish_row, int *finish_col) {
  if (begin_row == 0 && begin_col == 0) {
    *finish_row = begin_row + 1;
    *finish_col = begin_col;
    return;
  }
  if (begin_row == 0 && begin_col == n_cols - 1) {
    *finish_row = begin_row;
    *finish_col = begin_col - 1;
    return;
  }
  if (begin_row == n_rows - 1 && begin_col == 0) {
    *finish_row = begin_row;
    *finish_col = begin_col + 1;
    return;
  }
  if (begin_row == n_rows - 1 && begin_col == n_cols - 1) {
    *finish_row = begin_row - 1;
    *finish_col = begin_col;
    return;
  }

  if (begin_row == 0) {
    *finish_row = begin_row;
    *finish_col = begin_col - 1;
    return;
  }

  if (begin_row == n_rows - 1) {
    *finish_row = begin_row;
    *finish_col = begin_col + 1;
    return;
  }

  if (begin_col == 0) {
    *finish_row = begin_row + 1;
    *finish_col = begin_col;
    return;
  }

  if (begin_col == n_cols - 1) {
    *finish_row = begin_row - 1;
    *finish_col = begin_col;
  }
}

void rotate(int base_row, int base_col, int n_rows, int n_cols, int r) {
  int total = (n_rows + n_cols) * 2 - 4;

  static int buffer[1200];
  int row_id = 0;
  int col_id = 0;
  int finish_row = 0;
  int finish_col = 0;
  for (int i = 0; i < total; ++i) {
    if (i == r % total) {
      finish_row = row_id;
      finish_col = col_id;
    }
    buffer[i] = mat[base_row + row_id][base_col + col_id];
    rotate_step(n_rows, n_cols, row_id, col_id, &row_id, &col_id);
  }

  row_id = finish_row;
  col_id = finish_col;
  for (int i = 0; i < total; ++i)  {
    mat[base_row + row_id][base_col + col_id] = buffer[i];
    rotate_step(n_rows, n_cols, row_id, col_id, &row_id, &col_id);
  }
}

int main () {
  int m, n, r;

  scanf("%d %d %d", &m, &n, &r);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &mat[i][j]);
    }
  }

  for (int i = 0; i < (m >> 1) && i < (n >> 1); ++i) {
    rotate(i, i, m - i * 2, n - i * 2, r);
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j) {
        printf(" ");
      }
      printf("%d", mat[i][j]);
    }
    printf("\n");
  }
  return 0;
}

