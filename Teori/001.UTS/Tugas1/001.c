#include <stdio.h>
int main() {
  float mtk = 0, bindo = 0, ipa = 0, bing = 0, ips = 0, rata_rata;
  char nilai_huruf;
  char kasus[2][10] = {"Sempurna", "Baik"};
  printf("masukan nilai Matematika : ");
  scanf("%f", &mtk);
  printf("masukan nilai Bahasa Indonesia : ");
  scanf("%f", &bindo);
  printf("masukan nilai IPA : ");
  scanf("%f", &ipa);
  printf("masukan nilai Bahasa Inggris : ");
  scanf("%f", &bing);
  printf("masukan nilai IPS : ");
  scanf("%f", &ips);
  rata_rata = (mtk + bindo + ipa + bing + ips) / (float)5;
  printf("===========================================\n");
  if (rata_rata >= 90) {
    nilai_huruf = 'A';
    if (rata_rata == 100) {
      printf("Rata-Rata anda adalah %.2f Grade anda %c yaitu %s\n", rata_rata,
             nilai_huruf, kasus[0]);
    } else if (rata_rata < 100) {
      printf("Rata-Rata anda adalah %.2f Grade anda %c yaitu %s\n", rata_rata,
             nilai_huruf, kasus[1]);
    }
  } else if (rata_rata < 90 && rata_rata >= 80) {
    nilai_huruf = 'B';
    printf("Nilai Rata-Rata anda %.2f dan Grade anda %c\n", rata_rata,
           nilai_huruf);
  } else if (rata_rata < 80 && rata_rata >= 70) {
    nilai_huruf = 'C';
    printf("Nilai Rata-Rata anda %.2f dan Grade anda %c\n", rata_rata,
           nilai_huruf);
  } else if (rata_rata < 70 && rata_rata >= 60) {
    nilai_huruf = 'D';
    printf("Nilai Rata-Rata anda %.2f dan Grade anda %c\n", rata_rata,
           nilai_huruf);
  } else {
    nilai_huruf = 'E';
    printf("Nilai Rata-Rata anda %.2f dan Grade anda %c\n", rata_rata,
           nilai_huruf);
  }
  return 0;
}
