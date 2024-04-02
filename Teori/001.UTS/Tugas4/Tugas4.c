#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SIZE 3

typedef struct {
  char nama[20];
  int umur;
} data;

data stack[SIZE];
int top = -1;

bool is_empty() {
  if (top == -1) {
    return true;
  } else {
    return false;
  }
}

bool is_full() {
  if (top == SIZE - 1) {
    return true;
  } else {
    return false;
  }
}

void push(data datadiri) {
  if (is_full()) {
    printf("Stack Penuh.\n");
    sleep(1);
  } else {
    stack[++top] = datadiri;
    printf("=== Push data ===\nNama : %s\nUmur : %d\n", datadiri.nama,
           datadiri.umur);
    sleep(2);
  }
}

void pop() {
  if (is_empty()) {
    printf("Stack Kosong.\n");
    return;
    sleep(1);
  }
  data popped_value = stack[top--];
  printf("=== Pop data ===\nNama : %s\nUmur : %d\n", popped_value.nama,
         popped_value.umur);
  sleep(2);
}

void peek() {
  if (is_empty()) {
    printf("Stack Kosong.\n");
    sleep(1);
  } else {
    printf("=== Nilai Teratas ===\nNama : %s\nUmur : %d\n", stack[top].nama,
           stack[top].umur);
    sleep(2);
  }
}

void display() {
  if (is_empty()) {
    printf("Stack Kosong.\n");
    sleep(1);
  } else {
    printf("=== Stack Data ===\n");
    printf("Nama            Umur\n");
    for (int i = 0; i <= top; i++) {
      printf("%-15s %d\n", stack[i].nama, stack[i].umur);
    }
    sleep(2);
  }
}

int main() {
  printf("\e[H\e[2J\e[3J");
  bool isRunning = true;
  int c, choice;
  data datadiri;
  do {
    printf("\e[H\e[2J\e[3J");
    printf("top sekarang = %d\n", top);
    printf("1. Push\n2. Pop\n3. Peek/Top\n4. Display Data\n5. Exit\n");
    printf("Pilih Menu : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("\e[H\e[2J\e[3J");
      printf("Masukan Nama : ");
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      fgets(datadiri.nama, 20, stdin);
      datadiri.nama[strlen(datadiri.nama) - 1] = '\0';
      printf("Masukan Umur : ");
      scanf("%d", &datadiri.umur);
      printf("\e[H\e[2J\e[3J");
      push(datadiri);
      break;
    case 2:
      printf("\e[H\e[2J\e[3J");
      pop();
      break;
    case 3:
      printf("\e[H\e[2J\e[3J");
      peek();
      break;
    case 4:
      printf("\e[H\e[2J\e[3J");
      display();
      break;
    case 5:
      printf("\e[H\e[2J\e[3J");
      printf("Exiting...\n");
      isRunning = false;
      sleep(1);
      break;
    default:
      printf("\e[H\e[2J\e[3J");
      printf("Input Menu Tidak Ada\nSilahkan Pilih Menu Yang Lain.");
      sleep(1);
      break;
    }
  } while (isRunning);

  printf("\e[H\e[2J\e[3J");
  return 0;
}
