#include <stdbool.h>
#include <stdio.h>
void pengecekan();
int binary_Return(int angka);
void binary_noReturn();
int main() {
  bool isRunning = true;
  int menu, menu2;
  while (isRunning) {
    printf("=== Menu ===\n");
    printf("1.Pengecekan Angka Ganjil Atau Genap\n");
    printf("2.Pengubahan Bilangan Decimal Ke Binary\n");
    printf("3.Exit\n");
    printf("Pilih Menu : ");
    scanf("%d", &menu);
    switch (menu) {
    case 1:
      printf("\e[H\e[2J\e[3J");
      pengecekan();
      printf("\n");
      break;
    case 2:
      printf("\e[H\e[2J\e[3J");
      do {
        menu2 = 0;
        printf("Pilih 1/2\n");
        printf("1.Dengan Return\n");
        printf("2.Tanpa Return\n");
        printf("3.Exit\n");
        printf("menu yang di pilih : ");
        scanf("%d", &menu2);
        if (menu2 == 1) {
          printf("\e[H\e[2J\e[3J");
          int binary, angka;
          printf("angka yang ingin di convert : ");
          scanf("%d", &angka);
          printf("\e[H\e[2J\e[3J");
          printf("Angka Decimal = %d\n", angka);
          binary = binary_Return(angka);
          printf("Angka Binary = %d\n\n", binary);
        } else if (menu2 == 2) {
          binary_noReturn();
        }
      } while (menu2 != 3);
      printf("\e[H\e[2J\e[3J");
      printf("\n");
      break;
    case 3:
      isRunning = false;
      printf("\e[H\e[2J\e[3J");
      printf("Terima Kasih Telah Mengunakan Program\n");
      printf("Nama : Gendhi Ramona Prastyo\n");
      printf("NIM : 1203230011\n");
      break;
    default:
      printf("\e[H\e[2J\e[3J");
      printf("Inputan Menu Tidak Ada\n");
    }
  }
  return 0;
}
void pengecekan() {
  int angka;
  printf("masukan angka : ");
  scanf("%d", &angka);
  if (angka % 2 == 0) {
    printf("angka : %d merupakan angka genap\n", angka);
  } else {
    printf("angka : %d merupakan angka ganjil\n", angka);
  }
}
int binary_Return(int angka) {
  int binary = 0, p = 1;
  while (angka > 0) {
    binary += (angka % 2) * p;
    angka /= 2;
    p *= 10;
  }
  return binary;
}
void binary_noReturn() {
  printf("\e[H\e[2J\e[3J");
  int binary = 0, p = 1;
  int angka;
  printf("angka yang ingin di convert : ");
  scanf("%d", &angka);
  printf("\e[H\e[2J\e[3J");
  printf("Angka Decimal = %d\n", angka);
  while (angka > 0) {
    binary += (angka % 2) * p;
    angka /= 2;
    p *= 10;
  }
  printf("Angka Binary = %d\n\n", binary);
}
