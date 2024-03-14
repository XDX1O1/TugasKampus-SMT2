#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired(int *lengthOfText) {
  printf("The length of your text is less than specified, please update your "
         "text\n");
  *lengthOfText = MIN_LENGTH;
}

void equalThanRequired() { printf("Thank you, Your text length is correct\n"); }

void moreThanRequired(int *lengthOfText) {
  printf("Your text is to long, please reduce the text\n");
  *lengthOfText = MIN_LENGTH;
}

int checkLenghtRequirement(char *text) {
  int length = strlen(text);
  printf("Yout Text Length : %d\n", length);
  if (length < MIN_LENGTH)
    return 0;
  else if (length == MIN_LENGTH)
    return 1;
  else
    return 2;
}

int main() {
  int length, lengthOfText, selectOption;
  FILE *fptr = NULL;
  char text[MAX_LENGTH];

  fptr = fopen("file.txt", "r");

  if (fptr == NULL) {
    printf("Error\n");
    exit(1);
  }

  fgets(text, MAX_LENGTH, fptr);

  fclose(fptr);

  selectOption = checkLenghtRequirement(text);

  void (*options[3])(int *) = {lessThanRequired, equalThanRequired,
                               moreThanRequired};
  options[selectOption](&lengthOfText);

  printf("\nThe Length is updated to %d\n", lengthOfText);

  return 0;
}
