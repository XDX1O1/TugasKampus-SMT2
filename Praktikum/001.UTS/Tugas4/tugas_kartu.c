#include <stdio.h>

int nilai_kartu(char cards) {
  if (cards == 'J')
    return 11;
  else if (cards == 'Q')
    return 12;
  else if (cards == 'K')
    return 13;
  else if (cards == '1')
    return 10;
  else
    return cards - '0';
}

void pertukaran(char *cards, int n) {
  for (int i = 0; i < n; i++) {
    printf("%c ", cards[i]);
  }
  printf("\n");
}

int swapping(int n, char *cards) {
  int swaps = 0;
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (nilai_kartu(cards[j]) < nilai_kartu(cards[min_idx])) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      char temp = cards[i];
      cards[i] = cards[min_idx];
      cards[min_idx] = temp;
      swaps++;

      printf("Pertukaran %d : ", swaps);
      pertukaran(cards, n);
    }
  }
  return swaps;
}

int main() {
  int n;
  scanf("%d", &n);

  char cards[n];
  for (int i = 0; i < n; i++) {
    scanf(" %c", &cards[i]);
  }

  int swaps = swapping(n, cards);
  printf("%d\n", swaps);

  return 0;
}
