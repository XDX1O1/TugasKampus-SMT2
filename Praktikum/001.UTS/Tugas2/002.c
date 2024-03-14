#include <stdio.h>
#include <string.h>

void removeSpaces(char *input) {
  int i, j;

  for (i = 0; input[i] != 0; i++) {
    while (input[i] == ' ') {
      for (j = i; input[j] != 0; j++) {
        input[j] = input[j + 1];
      }
      input[j] = '\0';
    }
  }
}

void sortString(char *input) {
  int i, j, panjangkata;
  char temp;
  panjangkata = strlen(input);
  for (i = 1; i < panjangkata; i++) {
    for (j = 0; j < panjangkata - i; j++) {
      if (input[j] < input[j + 1]) {
        temp = input[j];
        input[j] = input[j + 1];
        input[j + 1] = temp;
      }
    }
  }
}

int main() {
  char input[1000];
  int panjangkata;

  printf("Masukan String Yang Di inginkan : ");
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  removeSpaces(input);

  sortString(input);

  printf("%s\n", input);

  return 0;
}
