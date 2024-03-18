#include <stdio.h>

int isValid(int x, int y) {
  //
  return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
  int movesX[] = {2, 1, -1, -2, -2, -1, 1, 2};
  int movesY[] = {1, 2, 2, 1, -1, -2, -2, -1};

  for (int k = 0; k < 8; k++) {
    int nextX = i + movesX[k];
    int nextY = j + movesY[k];
    if (isValid(nextX, nextY)) {
      *(chessBoard + nextX * size + nextY) = 1;
    }
  }
}

int main() {
  int i, j;
  scanf("%d %d", &i, &j);
  int size = 8;
  int chessBoard[size][size];

  for (int x = 0; x < size; x++) {
    for (int y = 0; y < size; y++) {
      chessBoard[x][y] = 0;
    }
  }

  printf("\n");
  koboImaginaryChess(i, j, size, (int *)chessBoard);

  for (int x = 0; x < size; x++) {
    for (int y = 0; y < size; y++) {
      printf("%d ", chessBoard[x][y]);
    }
    printf("\n");
  }

  return 0;
}
