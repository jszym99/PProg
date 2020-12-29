#ifndef STRUKTURY_H
#define STRUKTURY_H

/* typ do przechowywania obrazów monochoromatycznych */
typedef struct {
int typ; // P2 lub P3
int wymx, wymy, odcienie;
int **piksele;
int kolor; // kolor, na którym dokonywane są opreacje (tylko P3)
} t_obraz;

/* strukura do zapamietywania opcji podanych w wywolaniu programu */
typedef struct
{
  FILE *plik_we, *plik_wy;                             /* uchwyty do pliku wej. i wyj. */
  char *nazwa_pliku;
  int kolor, negatyw, progowanie, pol_prog_biel, pol_prog_czern,gamma,zmiana_poz, konturowanie, rozm_x, rozm_y, roz_histo, wyswietlenie; /* opcje */
  int w_progu, w_czern, w_biel;                         /* wartosc progu dla opcji progowanie */
  float w_gamma;
  int w_kol; // kolor
} t_opcje;

#endif
